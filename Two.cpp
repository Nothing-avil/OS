#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

// Function declarations
void displayCommands();
void listFiles(const std::vector<std::string>& files);
void createFile(std::vector<std::string>& files, const std::string& filename);
void deleteFile(std::vector<std::string>& files, const std::string& filename);
void openFile(const std::vector<std::string>& files, const std::string& filename);
void editFile(const std::vector<std::string>& files, const std::string& filename);
void renameFile(std::vector<std::string>& files, const std::string& oldname, const std::string& newname);
void searchFiles(const std::vector<std::string>& files, const std::string& keyword);
void executeProgram(const std::string& filename);
void shutdown();

int main() {
    std::vector<std::string> files;
    std::string command;

    std::cout << "Welcome to MyOS!\n";
    displayCommands();

    while (true) {
        std::cout << "\nEnter a command: ";
        std::getline(std::cin, command);

        // Splitting the command into tokens
        std::vector<std::string> tokens;
        std::string token;
        std::stringstream ss(command);
        while (ss >> token) {
            tokens.push_back(token);
        }

        if (tokens.empty()) {
            continue;
        }

        if (tokens[0] == "help") {
            displayCommands();
        } else if (tokens[0] == "list") {
            listFiles(files);
        } else if (tokens[0] == "create") {
            if (tokens.size() >= 2) {
                createFile(files, tokens[1]);
            } else {
                std::cout << "Invalid command: create\n";
            }
        } else if (tokens[0] == "delete") {
            if (tokens.size() >= 2) {
                deleteFile(files, tokens[1]);
            } else {
                std::cout << "Invalid command: delete\n";
            }
        } else if (tokens[0] == "open") {
            if (tokens.size() >= 2) {
                openFile(files, tokens[1]);
            } else {
                std::cout << "Invalid command: open\n";
            }
        } else if (tokens[0] == "edit") {
            if (tokens.size() >= 2) {
                editFile(files, tokens[1]);
            } else {
                std::cout << "Invalid command: edit\n";
            }
        } else if (tokens[0] == "rename") {
            if (tokens.size() >= 3) {
                renameFile(files, tokens[1], tokens[2]);
            } else {
                std::cout << "Invalid command: rename\n";
            }
        } else if (tokens[0] == "search") {
            if (tokens.size() >= 2) {
                searchFiles(files, tokens[1]);
            } else {
                std::cout << "Invalid command: search\n";
            }
        } else if (tokens[0] == "execute") {
            if (tokens.size() >= 2) {
                executeProgram(tokens[1]);
            } else {
                std::cout << "Invalid command: execute\n";
            }
        } else if (tokens[0] == "shutdown") {
            shutdown();
            break;
        } else {
            std::cout << "Unknown command. Type 'help' for available commands.\n";
        }
    }

    std::cout << "Shutting down MyOS. Goodbye!\n";
    return 0;
}

// Function definitions

void displayCommands() {
    std::cout << "Available commands:\n";
    std::cout << "help - Display available commands\n";
    std::cout << "list - List all files\n";
    std::cout << "create <filename> - Create a new file\n";
    std::cout << "delete <filename> - Delete a file\n";
    std::cout << "open <filename> - Open a file\n";
    std::cout << "edit <filename> - Edit a file\n";
    std::cout << "rename <oldname> <newname> - Rename a file\n";
    std::cout << "search <keyword> - Search for files containing a keyword\n";
    std::cout << "execute <filename> - Execute a program\n";
    std::cout << "shutdown - Shut down the operating system\n";
    std::cout << "-----------------------\n";
}

void listFiles(const std::vector<std::string>& files) {
    std::cout << "Files:\n";
    if (files.empty()) {
        std::cout << "No files found.\n";
    } else {
        for (const auto& file : files) {
            std::cout << file << "\n";
        }
    }
}

void createFile(std::vector<std::string>& files, const std::string& filename) {
    for (const auto& file : files) {
        if (file == filename) {
            std::cout << "File already exists: " << filename << "\n";
            return;
        }
    }

    std::ofstream newFile(filename);
    if (newFile.is_open()) {
        newFile.close();
        files.push_back(filename);
        std::cout << "File created: " << filename << "\n";
    } else {
        std::cout << "Failed to create file: " << filename << "\n";
    }
}

void deleteFile(std::vector<std::string>& files, const std::string& filename) {
    for (auto it = files.begin(); it != files.end(); ++it) {
        if (*it == filename) {
            if (std::remove(filename.c_str()) == 0) {
                files.erase(it);
                std::cout << "File deleted: " << filename << "\n";
            } else {
                std::cout << "Failed to delete file: " << filename << "\n";
            }
            return;
        }
    }
    std::cout << "File not found: " << filename << "\n";
}

void openFile(const std::vector<std::string>& files, const std::string& filename) {
    for (const auto& file : files) {
        if (file == filename) {
            std::cout << "Opening file: " << filename << "\n";
            // Add your file opening logic here
            return;
        }
    }
    std::cout << "File not found: " << filename << "\n";
}

void editFile(const std::vector<std::string>& files, const std::string& filename) {
    for (const auto& file : files) {
        if (file == filename) {
            std::cout << "Editing file: " << filename << "\n";
            // Add your file editing logic here
            return;
        }
    }
    std::cout << "File not found: " << filename << "\n";
}

void renameFile(std::vector<std::string>& files, const std::string& oldname, const std::string& newname) {
    for (auto& file : files) {
        if (file == oldname) {
            if (std::rename(oldname.c_str(), newname.c_str()) == 0) {
                file = newname;
                std::cout << "File renamed: " << oldname << " to " << newname << "\n";
            } else {
                std::cout << "Failed to rename file: " << oldname << "\n";
            }
            return;
        }
    }
    std::cout << "File not found: " << oldname << "\n";
}

void searchFiles(const std::vector<std::string>& files, const std::string& keyword) {
    std::cout << "Search results for keyword '" << keyword << "':\n";
    bool found = false;
    for (const auto& file : files) {
        if (file.find(keyword) != std::string::npos) {
            std::cout << file << "\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "No files found matching the keyword.\n";
    }
}

void executeProgram(const std::string& filename) {
    std::cout << "Executing program: " << filename << "\n";
    // Add your program execution logic here
}

void shutdown() {
    std::cout << "Shutting down the operating system...\n";
    // Add your shutdown logic here
}
