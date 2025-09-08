#include "student.hpp"
#include "exceptions.hpp"
#include <utility>
#include <nlohmann/json.hpp>

Student Student::from_json(const nlohmann::json& j) {
  int id = j.at("id").get<int>();
  std::string name = j.at("name").get<std::string>();
  std::string email = j.at("email").get<std::string>();
  int grad_year = j.at("grad_year").get<int>();
  std::vector<std:: string> courses = j.at("courses").get<std::vector<std::string>>();

  if (grad_year < 2000) throw ValidationError("grad_year too small");
  if (id_ <= 0) throw ValidationError("Validation must be positive");
  if (name_.empty()) throw ValidationError("name is required");
    validate_email(email_);
    return Student(id, std::move(name), std::move(email), grad_year, std::move(courses));
}

