#include <iostream>
#include <string>
#include <vector>
#include <sstream>

/**
 * @brief Displays the available commands.
 */
void displayCommands() {
    std::cout << "Available commands:\n";
    std::cout << "1. help - Display available commands\n";
    std::cout << "2. list - List all files\n";
    std::cout << "3. create <filename> - Create a new file\n";
    std::cout << "4. delete <filename> - Delete a file\n";
    std::cout << "5. open <filename> - Open a file\n";
    std::cout << "6. edit <filename> - Edit a file\n";
    std::cout << "7. rename <oldname> <newname> - Rename a file\n";
    std::cout << "8. search <keyword> - Search for files containing a keyword\n";
    std::cout << "9. execute <filename> - Execute a program\n";
    std::cout << "10. shutdown - Shut down the operating system\n";
}

/**
 * @brief Lists all the files.
 * @param files The vector of file names.
 */
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

/**
 * @brief Creates a new file.
 * @param files The vector of file names.
 * @param filename The name of the new file to be created.
 */
void createFile(std::vector<std::string>& files, const std::string& filename) {
    for (const auto& file : files) {
        if (file == filename) {
            std::cout << "File already exists: " << filename << "\n";
            return;
        }
    }
    files.push_back(filename);
    std::cout << "File created: " << filename << "\n";
}

/**
 * @brief Deletes a file.
 * @param files The vector of file names.
 * @param filename The name of the file to be deleted.
 */
void deleteFile(std::vector<std::string>& files, const std::string& filename) {
    for (auto it = files.begin(); it != files.end(); ++it) {
        if (*it == filename) {
            files.erase(it);
            std::cout << "File deleted: " << filename << "\n";
            return;
        }
    }
    std::cout << "File not found: " << filename << "\n";
}

/**
 * @brief Opens a file.
 * @param files The vector of file names.
 * @param filename The name of the file to be opened.
 */
void openFile(const std::vector<std::string>& files, const std::string& filename) {
    for (const auto& file : files) {
        if (file == filename) {
            std::cout << "Opening file: " << filename << "\n";
            return;
        }
    }
    std::cout << "File not found: " << filename << "\n";
}

/**
 * @brief Edits a file.
 * @param files The vector of file names.
 * @param filename The name of the file to be edited.
 */
void editFile(std::vector<std::string>& files, const std::string& filename) {
    for (auto& file : files) {
        if (file == filename) {
            std::cout << "Editing file: " << filename << "\n";
            // Add your file editing logic here
            return;
        }
    }
    std::cout << "File not found: " << filename << "\n";
}

/**
 * @brief Renames a file.
 * @param files The vector of file names.
 * @param oldname The current name of the file.
 * @param newname The new name for the file.
 */
void renameFile(std::vector<std::string>& files, const std::string& oldname, const std::string& newname) {
    for (auto& file : files) {
        if (file == oldname) {
            file = newname;
            std::cout << "File renamed from " << oldname << " to " << newname << "\n";
            return;
        }
    }
    std::cout << "File not found: " << oldname << "\n";
}

/**
 * @brief Searches for files containing a keyword.
 * @param files The vector of file names.
 * @param keyword The keyword to search for in file names.
 */
void searchFiles(const std::vector<std::string>& files, const std::string& keyword) {
    std::cout << "Search results:\n";
    bool found = false;
    for (const auto& file : files) {
        if (file.find(keyword) != std::string::npos) {
            std::cout << file << "\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "No files found containing the keyword: " << keyword << "\n";
    }
}

/**
 * @brief Executes a program.
 * @param filename The name of the program file to be executed.
 */
void executeProgram(const std::string& filename) {
    std::cout << "Executing program: " << filename << "\n";
    // Add your program execution logic here
}

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
            break;
        } else {
            std::cout << "Unknown command. Type 'help' for available commands.\n";
        }
    }

    std::cout << "Shutting down MyOS. Goodbye!\n";
    return 0;
}
