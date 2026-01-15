/**
 * @file randomstringgenerator.h
 * @author Василий Алтунин (skyr@altuninvv.ru)
 * @brief Файл содержит объявление класса RandomStringGenerator
 * @version 0.1.0
 * @date 07.01.2026
 * @bug Багов не обнаружено
  *
 * @copyright Алтунин Василий 2026
 *
 * Файл содержит объявление класса RandomStringGenerator для генерации случайных строк
 *
 * @example examples/basic/main.cpp Файл содержит пример использования класса RandomStringGenerator
 *
 */


#ifndef RANDOMSTRINGGENERATOR_H
#define RANDOMSTRINGGENERATOR_H

#include <cstddef>
#include <string>

#pragma once

/**
 * @brief Пространство имён altuninvv::string содержит классы и функции для 
 обработки строк
 *
 */
namespace altuninvv::string {

/**
 * @brief Класс для генерации случайных строк
 *  
 * @bug Багов не обнаружено
 * @details 
 * Класс для генерации случайных строк
 * 
 * @warning Нет предупреждений
 */

class RandomStringGenerator {
public:
/**
 * @brief Конструктор класса
 * 
 * @param notAllowedChars - символы, которые не будут использованы при генерации случайно строки
 * @param isSpecialChars - использовать или нет специальные символы при генерации строки. 
 К таким символам относятся: !@#$%^&*()_+-=[]{}|;':\",./<>?
 */
  RandomStringGenerator(std::string notAllowedChars,
                        bool isSpecialChars = false);
 /**
  * @brief Деструктор класса
  * 
  */
  ~RandomStringGenerator();

  /**
   * @brief Генерирует случайную строку заданной длины
   * 
   * @param length - длина тсроки
   * @return std::string - случайная строка
   */
  std::string getRandomStr(std::size_t length);

private:

/**
 * @brief Находит и удаляет указанный символ из строки разрешенных символов
 * 
 * @param val - символ для удаления
 */
  void removeChar(const char &val);

  /**
   * @brief Символы, разрешенные для использования при генерации случайных строк
   * 
   */
  std::string allowedChars;
  /**
   * @brief Символы запрещенные для использования при генерации случайных строк
   * 
   */
  std::string notAllowedChars = "";
  /**
   * @brief Все буквы и цифры используемые для генерации случайных строк
   * 
   */
  std::string alphaNumChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                              "abcdefghijklmnopqrstuvwxyz"
                              "0123456789";

  std::string specialChars = "!@#$%^&*()_+-=[]{}|;':\",./<>?";
};

} // namespace altuninvv::string 

#endif