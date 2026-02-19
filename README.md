# Linux Mini-EDR (Endpoint Detection & Response)
- A User-Space runtine process monitor written in C++17 to hunt for suspicious execution behaviors on Linux.

# Overview
- When malware is obfuscated using my 'XOR Crypter', it successfully bypasses my 'Static Scanner'. However, the CPU cannot execute encrypted code. To execute, the malware must decrypt itself in RAM.
- This EDR acts as a runtime hunter to catch the malware the moment it executes. It utilizes 'std::filesystem' to iterate through the Linux '/proc' filesystem in real time. By reading the '.exe' symlinks of active PIDs, it extracts the true execution path from memory and uses string matching to flag processes running from unauthroized directories (like '/tmp').

# How to run it
1. Run: './build.sh'
2. Run the EDR with sudo: 'sudo./edr'
