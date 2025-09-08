#include "instructor.hpp"
Instructor Instructor::from_json(const nlohmann::json& j) {
    int id = j.at("id").get<int>();
    std::string name = j.at("name").get<std::string>();
    std::string email = j.at("email").get<std::string>();
    std::string office = j.at("office").get<std::string>();
    std::vector<std::string> teaches = j.at("teaches").get<std::vector<std::string>>();

    if (office.empty()) {
        throw ValidationError("office is required");
    }

    return Instructor(id, std::move(name), std::move(email), std::move(office), std::move(teaches));
}