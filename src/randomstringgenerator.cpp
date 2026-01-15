/**
 * @file randomstringgenerator.h
 * @author Василий Алтунин (skyr@altuninvv.ru)
 * @brief Файл содержит реализацию класса RandomStringGenerator
 * @version 0.1.0
 * @date 07.01.2026
 * @bug Багов не обнаружено
 *
 * @copyright Алтунин Василий 2026
 *
 * Файл содержит реализацию класса RandomStringGenerator для генерации случайных
 * строк
 *
 * @example examples/basic/main.cpp Файл содержит пример использования класса
 * RandomStringGenerator
 *
 */

#include "randomstringgenerator.h"

#include <algorithm>
#include <random>

/**
 * @brief Пространство имён altuninvv::string содержит классы и функции для
 обработки строк
 *
 */
namespace altuninvv::string {

/**
 * @brief Конструктор класса
 *
 * @param notAllowedChars - символы, которые не будут использованы при генерации
 случайной строки
 * @param isSpecialChars - использовать или нет специальные символы при
 генерации строки. К таким символам относятся: !@#$%^&*()_+-=[]{}|;':\",./<>?
 */
RandomStringGenerator::RandomStringGenerator(std::string notAllowedChars,
                                             bool isSpecialChars) {

  if (isSpecialChars) {
    this->allowedChars = this->alphaNumChars + this->specialChars;
  } else {
    this->allowedChars = this->alphaNumChars;
  }

  this->notAllowedChars = notAllowedChars;

  for (auto i : this->notAllowedChars) {
    this->removeChar(i);
  }
}

/**
 * @brief Деструктор класса
 *
 */
RandomStringGenerator::~RandomStringGenerator() {}

/**
 * @brief Генерирует случайную строку заданной длины
 *
 * @param length - длина тсроки
 * @return std::string - случайная строка
 */
std::string RandomStringGenerator::getRandomStr(std::size_t length) {

  std::random_device rd;
  std::mt19937 generator(rd());

  std::uniform_int_distribution<> distribution(0,
                                               this->allowedChars.length() - 1);

  std::string randomString;
  randomString.reserve(length);

  for (size_t i = 0; i < length; i++) {
    randomString += this->allowedChars[distribution(generator)];
  }

  return randomString;
}

/**
 * @brief Находит и удаляет указанный символ из строки разрешенных символов
 *
 * @param val - символ для удаления
 */
void RandomStringGenerator::removeChar(const char &val) {
  this->allowedChars.erase(
      std::remove(this->allowedChars.begin(), this->allowedChars.end(), val),
      this->allowedChars.end());
}

} // namespace altuninvv::string