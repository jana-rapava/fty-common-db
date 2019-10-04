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

/*
@header
    fty_common_db_limitations - Class which implements generic asset creation limitations
@discuss
@end
*/

#include "fty_common_db_classes.h"

namespace fty
{
    DBLimitationsAccessor::DBLimitationsAccessor(fty::SyncClient & requestClient)
        : m_requestClient(requestClient)
      {}

    uint32_t DBLimitationsAccessor::getCreditsPerAsset(const std::string& asset_json)
    {
        return 0;
    }

    uint32_t DBLimitationsAccessor::getCreditsAvailable()
    {
        return 0;
    }

    uint32_t DBLimitationsAccessor::getCreditsTotalConsumed()
    {
        return 0;
    }

    std::string DBLimitationsAccessor::activateAsset(const std::string& asset_json)
    {
        //m_assets.push_back(asset_json);
        return std::string();
    }

    std::string DBLimitationsAccessor::deactivateAsset(const std::string& asset_json)
    {
        /*auto it = m_assets.begin();
        while (it != m_assets.end())
        {
            if (*it == asset_json)
            {
                it = m_assets.erase (it);
                break;
            }
            it++;
        }*/

        return std::string();
    }
} // end namespace

std::vector<std::pair<std::string,bool>> fty_common_db_limitations_accessor_test(fty::SyncClient & syncClient)
{
  std::vector<std::pair<std::string,bool>> testsResults;

  //using namespace lic_cred;

  printf(" ** fty_common_db_limitations_accessor_test: \n");

  std::string testNumber;
  std::string testName;

//test 1.1 => Create and destroy DBLimitationsAccessor
  testNumber = "1.1";
  testName = "Create and destroy DBLimitationsAccessor";
  printf("\n-----------------------------------------------------------------------\n");
  {
    printf(" *=>  Test #%s %s\n", testNumber.c_str(), testName.c_str());
    try
    {
      fty::DBLimitationsAccessor accessor(syncClient);

      printf(" *<=  Test #%s > OK\n", testNumber.c_str());
      testsResults.emplace_back (" Test #"+testNumber+" "+testName,true);
    }
    catch(const std::exception& e)
    {
      printf(" *<=  Test #%s > Failed\n", testNumber.c_str());
      printf("Error: %s\n",e.what());
      testsResults.emplace_back (" Test #"+testNumber+" "+testName,false);
    }
  }


//end of tests
  return testsResults;
}
