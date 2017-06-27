///////////////////////////////////////////////////////////////////
//
// mSIGNA
//
// filesystem.cpp
//
// Copyright (c) 2013-2014 Eric Lombrozo
// Copyright (c) 2011-2016 Ciphrex Corp.
//
// Distributed under the MIT software license, see the accompanying
// file LICENSE or http://www.opensource.org/licenses/mit-license.php.
//

#if defined(HAVE_CONFIG_H)
#include "config/msigna-config.h"
#endif

#include "filesystem.h"

#ifdef _WIN32
#include <shlobj.h>
#endif

#include <algorithm>
#include <boost/filesystem.hpp>

std::string getDefaultDataDir(const std::string& appName)
{
#ifdef _WIN32
    char path[1024] = "";
    if (SHGetSpecialFolderPathA(NULL, path, CSIDL_APPDATA, true))
        return (boost::filesystem::path(path) / appName).string();
    else
        throw std::runtime_error("getDefaultDataDir() - SHGetSpecialFolderPathA() failed.");
#else
    boost::filesystem::path dataDirPath;
    char const* homeDir = getenv("HOME");
    if (!homeDir || strlen(homeDir) == 0)
        dataDirPath = boost::filesystem::path("/");
    else
        dataDirPath = boost::filesystem::path(homeDir);
    
#if defined(__APPLE__) && defined(__MACH__)
    // This eventually needs to be put in proper wrapper (to support sandboxing)
    return (dataDirPath / "Library/Application Support" / appName).string();
#else
    std::string lowerAppName(appName);
    std::transform(lowerAppName.begin(), lowerAppName.end(), lowerAppName.begin(), ::tolower);
    return (dataDirPath / (std::string(".") + lowerAppName)).string();
#endif
#endif
}
