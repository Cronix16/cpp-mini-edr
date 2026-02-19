
#include <iostream>
#include <filesystem>
#include <string>
#include <thread>
#include <chrono>

 namespace fs = std::filesystem;
 void scan_processes() {
   for(const auto& entry: fs::directory_iterator("/proc")) {
     if(!entry.is_directory()) continue;
     std::string pid = entry.path().filename().string();
     if(!isdigit(pid[0])) continue;
     std::string exe_path = entry.path().string() + "/exe";
     if(fs::exists(exe_path)) {
       try {
         std::string real_path = fs::read_symlink(exe_path).string();
         if(real_path.find("/tmp") != std::string::npos) {
           std::cout <<"Suspicious execution from /tmp! PID: "<< pid << "->" << real_path << std::endl;
         }
         if(real_path.find("(deleted)") != std::string::npos) {
           std::cout <<"Ghost process detected! PID: "<< pid << "->" << real_path << std::endl;
         }
       }
       catch(...){
       }
     }
   }
 }

 int main() {
   std::cout <<"Starting Mini EDR Process Hunter"<< std::endl;
   std::cout <<"Monitoring RAM for suspicious activity. Press Ctrl+C to stop.\n"<< std::endl;
   while(true) {
     scan_processes();
     std::this_thread::sleep_for(std::chrono::seconds(2));
   }
   return 0;
 }
