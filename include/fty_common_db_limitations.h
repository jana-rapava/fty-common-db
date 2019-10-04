/*  =========================================================================
    fty_common_db_limitations - Class which implements generic asset creation limitations

    Copyright (C) 2014 - 2018 Eaton

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
    =========================================================================
*/

#ifndef FTY_COMMON_DB_LIMITATIONS_H_INCLUDED
#define FTY_COMMON_DB_LIMITATIONS_H_INCLUDED

namespace fty
{
    class DBLimitationsAccessor
    {
    public:
        /**
         * @brief Construct a new Accessor object
         *
         * @param Object implementing fty::SyncClient
         */
        explicit DBLimitationsAccessor(fty::SyncClient & requestClient);

        uint32_t getCreditsPerAsset(const std::string& asset_json);
        uint32_t getCreditsAvailable();
        uint32_t getCreditsTotalConsumed();
        std::string activateAsset(const std::string& asset_json);
        std::string deactivateAsset(const std::string& asset_json);
        bool isOperationAllowed (const std::string& operation)
        { return true; }

    private:
        fty::SyncClient & m_requestClient;

        std::vector<std::string> sendCommand(const std::string & command, const std::vector<std::string> & frames) const;

    };
        /*public:
            virtual std::string activateAsset(const std::string& asset_json);
            virtual std::string deactivateAsset(const std::string& asset_json);
            virtual bool isOperationAllowed (const std::string& operation);

        private:
            std::vector<std::string> m_assets;
    };*/
}

// Interface
std::vector<std::pair<std::string,bool>> fty_common_db_limitations_accessor_test(fty::SyncClient & syncClient);

#endif
