#include <iostream>
#include <vector>
#include <string>

class Logger {
private:
    std::vector<std::string> logs;
    static const int MAX_LOGS = 1000;
    int logCounter = 1;  // Replaces timestamp for ordering

    void addLog(const std::string& severity, const std::string& module, const std::string& message) {
        if (logs.size() >= MAX_LOGS) {
            logs.erase(logs.begin());  // Remove the oldest log
        }
        std::string formattedLog = "[" + std::to_string(logCounter++) + "] [" + severity + "] [" + module + "] " + message;
        logs.push_back(formattedLog);
    }

public:
    void logInfo(const std::string& module, const std::string& message) {
        addLog("INFO", module, message);
    }

    void logWarning(const std::string& module, const std::string& message) {
        addLog("WARN", module, message);
    }

    void logError(const std::string& module, const std::string& message) {
        addLog("ERROR", module, message);
    }

    friend class Auditor; // Gives controlled access to logs
};

class Auditor {
private:
    std::string authCode = "letMeIn";

public:
    bool authenticate(const std::string& code) const {
        return code == authCode;
    }

    std::vector<std::string> retrieveLogs(const Logger& logger, const std::string& code) const {
        if (authenticate(code)) {
            return logger.logs; // Return a copy (read-only)
        } else {
            std::cout << "Access denied: Invalid authentication.\n";
            return {};
        }
    }
};

// --- Demonstration ---
int main() {
    Logger logger;

    // Simulating log generation from different modules
    logger.logInfo("Network", "Connected to server.");
    logger.logWarning("Database", "Slow query detected.");
    logger.logError("Auth", "Unauthorized access attempt.");

    Auditor auditor;
    std::string code;

    std::cout << "\nEnter auditor password to view logs: ";
    std::cin >> code;

    std::vector<std::string> logs = auditor.retrieveLogs(logger, code);

    if (!logs.empty()) {
        std::cout << "\n--- LOGS ---\n";
        for (const auto& log : logs) {
            std::cout << log << "\n";
        }
    }

    return 0;
}
