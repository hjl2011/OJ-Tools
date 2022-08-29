// OI-Tools | Lib | Init
// This source code file is under MIT License.
// Copyright (c) 2022 hjl2011

#pragma once

inline void Init() {
    string GenerateTimeStamp;
    ifstream TimeStampFile("TIMESTAMP");
    if(TimeStampFile.fail()) return show_error(1);
    TimeStampFile >> GenerateTimeStamp;
    TimeStampFile.close();
    cout << "OI-Tools | v" << VERSION << " | ";
    if(string(VERSION).find("alpha") != string::npos) cout << "Alpha";
    else if(string(VERSION).find("beta") != string::npos) cout << "Beta";
    else if(string(VERSION).find("(LTS)") != string::npos) cout << "LTS";
    else if(string(VERSION).find("(Release)") != string::npos) cout << "Release";
    else cout << "Preview";
    cout << " | " << GenerateTimeStamp << "\nCopyright (c) 2022 hjl2011\n";
    cout << "Type \"help\", \"version\" or \"license\" for more information.\n\n>>> ";
    commandlist.insert({"version",Commands::version});
    commandlist.insert({"license",Commands::license});
    commandlist.insert({"exit",Commands::exit});
    commandlist.insert({"help",Commands::help});
    commandlist.insert({"goto",Commands::_goto});
    commandlist.insert({"wiki",Commands::wiki});
    commandlist.insert({"luogu-open",Commands::luogu_open});
}

inline void CommandInit() {
    commands.clear(),CommandInitStream.clear(),CommandInitStream.str(command);
    while(CommandInitStream >> temp) {
        _commands.push_back(temp);
        for(int i = 0;i < temp.length();i++) if((temp[i] >= 'a' && temp[i] <= 'z') || (temp[i] >= 'A' && temp[i] <= 'Z')) temp[i] |= 32;
        commands.push_back(temp);
    }
}