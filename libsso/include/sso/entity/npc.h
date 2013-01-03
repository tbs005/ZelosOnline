/*********************************************************************************
 *
 * This file is part of ZelosOnline.
 *
 * ZelosOnline is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * ZelosOnline is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright  2013  Rafael Dominguez (npcdoom)
 *
 *********************************************************************************/

#ifndef __ZELOS_LIBSSO_SSO_ENTITY_NPC_H__
#define __ZELOS_LIBSSO_SSO_ENTITY_NPC_H__

#include <vector>

#include <sso/entity/character.h>
#include <sso/entity/npc_task.h>

namespace sso
{
    class InteractiveNPC : public ICharacter
    {
    public:

        InteractiveNPC (const boost::shared_ptr<EntityProperty> &property);

        virtual ~InteractiveNPC ();

        virtual uint8_t getLevel () const;

        void setFortressActive (bool active);

        bool isFortressActive () const;

        std::string GetFortress () const;

        void SetFortressTax (const int16_t tax);

        int16_t GetFortressTax () const;

        void SetTeleportID (const uint16_t ID);

        uint16_t GetTeleportID () const;

        void InsertTask (const NPCTask &task);

        const std::vector<NPCTask>& GetAllTasks () const;

        std::vector<uint8_t> GetAvailableTasks (const uint8_t level) const;

        bool IsTaskAvailable (const uint8_t taskID, const uint8_t level) const;

    private:

        bool m_FortressActive;
        int16_t m_FortressTax;
        uint16_t m_TeleportID;

        std::vector<NPCTask> m_TaskList;
    };
}

#endif // __ZELOS_LIBSSO_SSO_ENTITY_NPC_H__
