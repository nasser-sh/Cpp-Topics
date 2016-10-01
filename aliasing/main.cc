/* Copyright (C) 2016 nasser-sh
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#include <map>
#include <memory>
#include <string>
#include <vector>


class Entity
{ };


namespace ancient
{
    typedef std::vector<std::unique_ptr<Entity>> EntitiyVector;
    typedef void (*EntityCallback)(Entity&);


    template <typename T>
    struct StringKeyMap
    {
        typedef std::map<std::string, T> type;
    };


    template <typename T>
    class Manager
    {
    private:
        typename StringKeyMap<T>::type m_collection;
    };


    void run()
    {
        StringKeyMap<Entity>::type entities;
    }
}


namespace modern
{
    using EntityVector = std::vector<std::unique_ptr<Entity>>;
    using EntityCallback = void (*) (Entity&);


    template <typename T>
    using StringKeyMap = std::map<std::string, T>;


    template <typename T>
    class Manager
    {
    private:
        StringKeyMap<T> m_collection;
    };

    
    void run()
    {
        StringKeyMap<Entity> entities;
    }
}

