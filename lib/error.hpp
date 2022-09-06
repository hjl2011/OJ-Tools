// OI-Tools | Lib | Error
// This source code file is under GPLv2.
// Copyright (c) 2022 hjl2011

#pragma once

inline void show_error(int errid) {
    if(!errid) {
        CreateLog(2,"The command you entered does not exist.\n");
        PrintERR("Error: The command you entered does not exist.");
        return ;
    }
    string err = string("Oops!\nAn error occurred.\nError message :  ") + to_string(errid) + " ";
    if(errid == -1) err += "Unknown Error";
    else if(errid == 1) err += "File does not exist";
    else err += "Unknown Error";
    err += "\n\nWould you like to visit the Issues page now?";
    if(MessageBox(nullptr,err.c_str(),"OI-Tools Error",MB_YESNO | MB_ICONERROR) == IDYES) system("start website/issues.url");
    exit(0);
}