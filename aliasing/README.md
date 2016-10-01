# Aliasing

## The new `typedef`

In C++98, aliasing is achieved with the `typedef` keyword, for example:
```C++
typedef std::vector<std::unique_ptr<Entity> > EntityVector;

typedef void (*EntityCallback)(Entity&);
```
C++11 offers a new syntax to achieve this, known as *alias declaration*. The following example achieves the same result is the code snippet above:
```C++
using EntityVector = std::vector<std::unique_ptr<Entity>>;

using EntityCallback = void(*)(Entity&);
```
In either case, both `EntityVector` and `EntityCallback` are *typedef-names*. They are merely aliases, and do not introduce new types. To illustrate:
```C++
using count = int;

void callback(count number) { }
void callback(int number) { }
```
In the scenario above, the `callback` function definitions are not overloads, but re-definitions of the same function, and an attempt to compile the above example will cause an error. In all of the contexts mentioned so far, there is no difference in the resulting typedef-name whether it was introduced using the `typedef` or `using` keyword, since they both have the same semantics. The following two statements declare the same *typedef-name*; the first statement declares the `EntityCallback` *typedef-name*, and second statement re-declares the same thing:
```C++
typedef void (*EntityCallback)(Entity&);
using EntityCallback = void(*)(Entity&);
```
## Alias templates

Alias declarations can be templetized, something which `typedef` does not natively support. In C++98, this was achieved with class templates and inner `typedef`s:
```C++
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
```

With alias declarations, this is natively supported:
```C++
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
```
Notice how in the modern C++ example, the need for the `typename` keyword goes away. This is because in the C++98 example, `type` in `StringKeyMap<T>::type` is a dependent name.


## `<type_traits>`

While alias declarations/templates have been supported since C++11, it is only until C++14 that they were implemented for type traits. Check your compiler (TM).

## References
1. Effective Modern C++: 42 Specific Ways to Improve Your Use of C++11 and C++14 (Scott Meyers, 2014)
2. Working Draft, Standard for the C++ Programming Language. Document number N3337 (2012) 
