#include "xtools.h"
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

using namespace std;
XCOM_API std::string GetDirData(std::string path) {
    string data = "";
    const char *dir = path.c_str();
    DIR *dp = 0;
    struct dirent *entry = 0;
    struct stat statbuf;
    dp = opendir(dir);
    if (dp == NULL)
        return data;
    chdir(dir);
    char buf[1024] = {0};

    while ((entry = readdir(dp)) != NULL) {
        lstat(entry->d_name, &statbuf);
        if (S_ISDIR(statbuf.st_mode)) continue;
        sprintf(buf, "%s,%ld;", entry->d_name, statbuf.st_size);
        data += buf;
    }

    //ȥ????β ;
    if (!data.empty()) {
        data = data.substr(0, data.size() - 1);
    }
    return data;
}


