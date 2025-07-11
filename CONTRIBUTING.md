# Руководство по вкладу в проект 🤝

Спасибо за интерес к улучшению Satisfactory Calculator Pro! Этот документ поможет вам внести свой вклад в проект.

## 📋 Оглавление

- [Кодекс поведения](#кодекс-поведения)
- [Как внести вклад](#как-внести-вклад)
- [Настройка среды разработки](#настройка-среды-разработки)
- [Стиль кода](#стиль-кода)
- [Процесс разработки](#процесс-разработки)
- [Тестирование](#тестирование)
- [Документация](#документация)

## 🤝 Кодекс поведения

Участвуя в этом проекте, вы соглашаетесь соблюдать наш [Кодекс поведения](CODE_OF_CONDUCT.md). Мы ожидаем от всех участников:

- **Уважения** ко всем участникам
- **Конструктивности** в обсуждениях  
- **Включенности** - приветствуем всех разработчиков
- **Профессионализма** в общении

## 🛠 Как внести вклад

### Типы вкладов

#### 🐛 Сообщения об ошибках
- Используйте [шаблон issue для багов](https://github.com/satisfactory-calculator/satisfactory-calculator/issues/new?template=bug_report.md)
- Предоставьте подробную информацию о воспроизведении
- Приложите скриншоты при необходимости

#### ✨ Предложения улучшений
- Используйте [шаблон issue для feature requests](https://github.com/satisfactory-calculator/satisfactory-calculator/issues/new?template=feature_request.md)
- Объясните проблему, которую решает ваше предложение
- Предложите возможную реализацию

#### 💻 Вклад в код
- Исправления ошибок
- Новые функции
- Оптимизация производительности
- Рефакторинг кода

#### 📝 Документация
- Улучшение README
- API документация
- Туториалы и примеры
- Комментарии в коде

#### 🌍 Переводы
- Перевод интерфейса
- Локализация документации
- Названия предметов на других языках

## 🔧 Настройка среды разработки

### Предварительные требования

```bash
# Qt 6.0+
sudo apt install qt6-base-dev qt6-tools-dev-tools  # Ubuntu/Debian
# или
brew install qt6  # macOS

# CMake 3.16+
sudo apt install cmake  # Ubuntu/Debian
# или  
brew install cmake  # macOS

# Git
sudo apt install git  # Ubuntu/Debian
# или
brew install git  # macOS
```

### Настройка проекта

1. **Fork репозитория**
   ```bash
   # Склонируйте ваш fork
   git clone https://github.com/YOUR_USERNAME/satisfactory-calculator.git
   cd satisfactory-calculator
   
   # Добавьте upstream remote
   git remote add upstream https://github.com/satisfactory-calculator/satisfactory-calculator.git
   ```

2. **Настройка сборки**
   ```bash
   mkdir build && cd build
   cmake .. -DCMAKE_BUILD_TYPE=Debug
   make -j$(nproc)
   ```

3. **Проверка установки**
   ```bash
   ./bin/SatisfactoryCalculator --version
   ```

### IDE настройка

#### Qt Creator
1. Откройте `CMakeLists.txt` как проект
2. Настройте Kit с Qt 6.0+
3. Выберите Debug конфигурацию

#### Visual Studio Code
1. Установите расширения:
   - C/C++
   - CMake Tools
   - Qt for Python (для подсветки Qt)
2. Откройте папку проекта
3. Используйте Command Palette: "CMake: Configure"

#### CLion
1. Откройте папку проекта
2. CLion автоматически определит CMake проект
3. Настройте Toolchain с Qt

## 📋 Стиль кода

### C++ стандарты

```cpp
// ✅ Хорошо
class CalculatorEngine : public QObject
{
    Q_OBJECT

public:
    explicit CalculatorEngine(QObject* parent = nullptr);
    
    // Используйте const correctness
    double calculateEfficiency(const GameRecipe& recipe) const;
    
private:
    // Префикс m_ для member переменных
    QMap<QString, double> m_cachedResults;
    
    // camelCase для методов
    void updateCacheEntry(const QString& key, double value);
};
```

### Соглашения именования

- **Классы**: `PascalCase` (например, `CalculatorEngine`)
- **Методы**: `camelCase` (например, `calculateProduction`) 
- **Переменные**: `camelCase` (например, `totalAmount`)
- **Member переменные**: `m_camelCase` (например, `m_cache`)
- **Константы**: `UPPER_CASE` (например, `MAX_DEPTH`)

### Форматирование

```cpp
// Отступы: 4 пробела
if (condition) {
    doSomething();
} else {
    doSomethingElse();
}

// Скобки на новой строке для классов и функций
void function()
{
    // код
}

// Инициализация в конструкторе
CalculatorEngine::CalculatorEngine(QObject* parent)
    : QObject(parent)
    , m_cache(1000)
    , m_maxDepth(20)
{
    initialize();
}
```

### Комментарии

```cpp
/**
 * @brief Calculates production requirements for given item
 * 
 * @param itemClass Class identifier of the item
 * @param amountPerMinute Required production rate
 * @param maxDepth Maximum recursion depth
 * @return CalculationResult with resource requirements
 */
CalculationResult calculateProduction(
    const QString& itemClass,
    double amountPerMinute,
    int maxDepth = 20
);
```

## 🔄 Процесс разработки

### 1. Создание ветки

```bash
# Синхронизируйтесь с upstream
git checkout main
git pull upstream main

# Создайте feature ветку
git checkout -b feature/amazing-feature
# или
git checkout -b fix/important-bug
# или
git checkout -b docs/update-readme
```

### 2. Разработка

- Делайте **небольшие, атомарные коммиты**
- Пишите **понятные commit сообщения**
- **Тестируйте** ваши изменения

```bash
# Хорошие commit сообщения
git commit -m "feat: add multi-threaded calculation engine"
git commit -m "fix: resolve memory leak in recipe caching"
git commit -m "docs: update installation instructions"
git commit -m "refactor: extract UI components to separate class"
```

### 3. Тестирование

```bash
# Запустите все тесты
cd build
ctest --output-on-failure

# Проверьте стиль кода
clang-format -i src/*.cpp include/*.h

# Проверьте на memory leaks (Linux)
valgrind --leak-check=full ./bin/SatisfactoryCalculator
```

### 4. Pull Request

1. **Убедитесь**, что все тесты проходят
2. **Обновите документацию** при необходимости
3. **Опишите изменения** в PR описании
4. **Связывайте с issues** используя "Closes #123"

```markdown
## Описание
Добавлен многопоточный движок расчетов для улучшения производительности.

## Изменения
- ✅ Добавлен класс `CalculationWorker`
- ✅ Реализован thread pool для параллельных вычислений
- ✅ Добавлены тесты производительности

## Тестирование
- [x] Unit тесты проходят
- [x] Интеграционные тесты проходят
- [x] Тестирование производительности показывает 3x ускорение

Closes #45
```

## 🧪 Тестирование

### Unit тесты

```cpp
// tests/test_calculator_engine.cpp
#include <QtTest>
#include "calculator_engine.h"

class TestCalculatorEngine : public QObject
{
    Q_OBJECT

private slots:
    void testBasicCalculation();
    void testAlternateRecipes();
    void testCachePerformance();
};

void TestCalculatorEngine::testBasicCalculation()
{
    CalculatorEngine engine;
    auto result = engine.calculateProduction({"Desc_IronPlate_C", 60.0});
    
    QVERIFY(result.success);
    QCOMPARE(result.rawResources["Desc_IronOre_C"], 90.0);
}
```

### Интеграционные тесты

```bash
# Запуск с различными конфигурациями
./bin/SatisfactoryCalculator --test-mode --config=minimal
./bin/SatisfactoryCalculator --test-mode --config=full
```

### Тесты производительности

```cpp
void TestPerformance::benchmarkLargeCalculation()
{
    QBENCHMARK {
        engine.calculateHubRequirements(95);  // Самый сложный уровень
    }
}
```

## 📚 Документация

### API документация

Используйте Doxygen комментарии:

```cpp
/**
 * @class CalculatorEngine
 * @brief High-performance calculation engine
 * 
 * Provides optimized calculation capabilities with caching,
 * multi-threading, and memory pooling.
 * 
 * @example
 * @code
 * CalculatorEngine engine;
 * auto result = engine.calculateProduction({"Desc_Computer_C", 10.0});
 * if (result.success) {
 *     qDebug() << "Required resources:" << result.rawResources;
 * }
 * @endcode
 */
```

### README обновления

При добавлении новых функций обновите:
- Раздел "Основные возможности"
- Скриншоты при необходимости
- Примеры использования

## 🏷 Версионирование

Мы используем [Semantic Versioning](https://semver.org/):

- **MAJOR** (1.0.0): Несовместимые изменения API
- **MINOR** (1.1.0): Новые функции с обратной совместимостью  
- **PATCH** (1.1.1): Исправления ошибок

## 🎯 Приоритетные области

### Высокий приоритет
- 🐛 Критические баги
- 🚀 Оптимизация производительности
- 🔧 Улучшения UX/UI

### Средний приоритет  
- ✨ Новые функции
- 📝 Документация
- 🧪 Покрытие тестами

### Низкий приоритет
- 🎨 Визуальные улучшения
- 🌍 Переводы
- 📋 Рефакторинг кода

## 💬 Получение помощи

- **GitHub Discussions**: для вопросов разработки
- **Discord**: для быстрого общения  
- **Issues**: для конкретных проблем
- **Email**: maintainers@satisfactory-calculator.org

## 🙏 Благодарность

Каждый вклад ценится! Ваше имя будет добавлено в:
- `CONTRIBUTORS.md`
- Release notes
- Раздел благодарностей в README

---

**Удачи в разработке! 🚀** 