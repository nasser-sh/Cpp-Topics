# Aliasing

## The new `typedef`

In C++98, aliasing was achieved using `typedef`, using something like this:

    typedef std::vector<std::unique_ptr<Entity> > EntityVector;

    typedef void (*EntityCallback)(Entity&);

C++11 offers a new syntax to achieve this, known as "alias declaration". The following example achieves the 

    using EntityVector = std::vector<std::unique_ptr<Entity>>;

    using EntityCallback = void(*)(Entity&);

In either case, both `EntityVector` and `EntityCallback` are "typedef-names". They are merely aliases, and do not introduce new types. For example:

    using count = int;

    void callback(count number) { }
    void callback(int number) { }

In the scenario above, the `callback` function declarations are not overloads, but re-definitions of the same function, and an attempt to compile the above example will cause an error.

## Alias templates

Alias declarations can be templetized, something which `typedef` did not support. In C++98, this was achieved with class templates and inner `typedef`s:

    template <typename T>
    struct StringKeyMap
    {
        typedef std::map<std::string, T> type;
    };


    // Definition
    StringKeyMap<Entity>::type entities;

    // As a class attribute
    template <typename T>
    class Manager
    {
    private:
        typename StringKeyMap<T>::type m_collection;
    };


With alias declarations, this is natively supported, and allows us to do away with the `type` hack

    template <typename T>
    using StringKeyMap = std::map<std::string, T>;

    // Definition
    StringKeyMap<Entity> entities;

    // As a class attribute
    template <typename T>
    class Manager
    {
    private:
        StringKeyMap<T> m_collection;
    };

Notice how in the modern C++ example, the need for the `typename` keyword goes away. This is because in the C++98 example, `type` in `StringKeyMap<T>::type` is a dependent name.


## `<type_traits>`

While alias declarations/templates have been supported since C++11, it is only until C++14 that they were implemented for type traits. Check your compiler (TM).

