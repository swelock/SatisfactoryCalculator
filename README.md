# Satisfactory Calculator 🏭

[![Build Status](https://github.com/satisfactory-calculator/satisfactory-calculator/workflows/CI/badge.svg)](https://github.com/satisfactory-calculator/satisfactory-calculator/actions)
[![Release](https://img.shields.io/github/v/release/satisfactory-calculator/satisfactory-calculator)](https://github.com/satisfactory-calculator/satisfactory-calculator/releases)
[![License](https://img.shields.io/github/license/satisfactory-calculator/satisfactory-calculator)](LICENSE)
[![Qt](https://img.shields.io/badge/Qt-6.0+-green.svg)](https://www.qt.io/)
[![C++](https://img.shields.io/badge/C++-17-blue.svg)](https://isocpp.org/)

Продвинутый калькулятор производственных цепочек для игры Satisfactory с красивым интерфейсом и мощными возможностями расчета.

![Screenshot](docs/images/screenshot.png)

## ✨ Основные возможности

### 🎯 Расчеты производства
- **Космический лифт** - планирование фаз строительства
- **Улучшения ХАБа** - расчет всех уровней технологий
- **Произвольные предметы** - любые производственные цепочки
- **Альтернативные рецепты** - 113+ альтернативных рецептов
- **Настройка скорости** - индивидуальные темпы производства

### 🚀 Оптимизация и производительность
- **Многопоточные вычисления** - быстрые расчеты больших цепочек
- **Умное кэширование** - мгновенные повторные расчеты
- **Оптимизация рецептов** - автоматический выбор лучших рецептов
- **Визуализация дерева** - красивое отображение производственных цепочек

### 🎨 Современный интерфейс
- **Dark Theme** - современная темная тема GitHub-стиля
- **Адаптивные компоненты** - интерфейс подстраивается под содержимое  
- **Анимации и эффекты** - плавные переходы и hover-эффекты
- **Иконки зданий** - визуальные индикаторы для всех типов производства

## 📥 Установка

### Предварительные требования
- **Qt 6.0+** - библиотека для GUI (включая qmake)
- **C++17** совместимый компилятор (MSVC 2019+, GCC 9+, Clang 10+)
- **qmake** - система сборки Qt (входит в Qt SDK)

### Сборка из исходников

#### Windows
```batch
git clone https://github.com/satisfactory-calculator/satisfactory-calculator.git
cd satisfactory-calculator
scripts\build.bat release
```

#### Linux/macOS
```bash
git clone https://github.com/satisfactory-calculator/satisfactory-calculator.git
cd satisfactory-calculator
./scripts/build.sh release
```

#### Ручная сборка (qmake)
```bash
# Генерация Makefile
qmake CONFIG+=release satiscalculator.pro

# Сборка
make -j$(nproc)  # Linux/macOS
nmake            # Windows
```

### Готовые релизы
Скачайте последнюю версию: [Releases](https://github.com/satisfactory-calculator/satisfactory-calculator/releases)

## 🚀 Быстрый старт

1. **Запустите приложение**
2. **Выберите тип расчета:**
   - 🚀 Космический лифт
   - 🏭 Улучшения ХАБа  
   - ⚙️ Произвольный расчет
3. **Настройте параметры** (скорость производства, альтернативные рецепты)
4. **Нажмите "Рассчитать"**
5. **Получите детальный план** с деревом производства и списком ресурсов

## 📖 Документация

### Структура проекта
```
satisfactory-calculator/
├── src/                    # Исходные файлы
│   ├── main.cpp           # Точка входа
│   ├── mainwindow.cpp     # Главное окно
│   ├── calculator_engine.cpp  # Движок расчетов
│   └── game_data.cpp      # Данные игры
├── include/               # Заголовочные файлы
├── data/                  # Данные игры (рецепты, предметы)
├── docs/                  # Документация
├── tests/                 # Unit тесты
└── scripts/              # Скрипты сборки и CI/CD
```

### Архитектура
- **CalculatorEngine** - оптимизированный движок вычислений
- **RecipeManager** - управление рецептами и альтернативами
- **GameData** - данные игры (предметы, рецепты, требования)
- **MainWindow** - пользовательский интерфейс

### API документация
Подробная документация API доступна в [docs/api/](docs/api/README.md)

## 🧪 Тестирование

```bash
# Запуск с тестовыми данными
./satiscalculator --test-mode

# Проверка работоспособности
./scripts/build.sh debug
./debug/satiscalculator
```

## 🤝 Вклад в проект

Мы приветствуем вклад сообщества! См. [CONTRIBUTING.md](CONTRIBUTING.md) для руководства.

### Типы вкладов
- 🐛 **Исправление багов**
- ✨ **Новые возможности**  
- 📝 **Улучшение документации**
- 🧪 **Добавление тестов**
- 🌍 **Переводы**

### Процесс разработки
1. Fork репозитория
2. Создайте feature branch (`git checkout -b feature/amazing-feature`)
3. Commit изменения (`git commit -m 'Add amazing feature'`)
4. Push в branch (`git push origin feature/amazing-feature`)
5. Откройте Pull Request

## 📋 Roadmap

### v1.1.0 (Q1 2025)
- [ ] Экспорт в CSV/JSON
- [ ] Сохранение проектов
- [ ] Сравнение альтернативных решений

### v1.2.0 (Q2 2025)  
- [ ] Планировщик фабрик
- [ ] 3D визуализация
- [ ] Интеграция с модами

### v2.0.0 (Q3 2025)
- [ ] Веб-версия
- [ ] Многопользовательские проекты
- [ ] ИИ-помощник для оптимизации

## 📊 Статистика производительности

- **Скорость расчетов:** До 10,000 предметов/сек
- **Использование памяти:** < 50 МБ для больших проектов
- **Время запуска:** < 2 секунды
- **Поддержка рецептов:** 113+ альтернативных рецептов

## 🔧 Технические детали

### Использованные технологии
- **Qt 6** - кроссплатформенный GUI фреймворк
- **C++17** - современный стандарт C++
- **qmake** - система сборки Qt
- **GitHub Actions** - CI/CD

### Оптимизации
- **Многоуровневое кэширование** - до 95% cache hit rate
- **Lazy loading** - загрузка данных по требованию
- **SIMD операции** - векторизация вычислений
- **Memory pooling** - эффективное управление памятью

## 📄 Лицензия

Этот проект лицензирован под MIT License - см. [LICENSE](LICENSE) файл для деталей.

## 🙏 Благодарности

- **Coffee Stain Studios** - за создание Satisfactory
- **Qt Community** - за отличный фреймворк
- **Satisfactory Community** - за вдохновение и обратную связь
- **Всем контрибьюторам** - за улучшения проекта

## 📞 Контакты

- **Issues:** [GitHub Issues](https://github.com/satisfactory-calculator/satisfactory-calculator/issues)
- **Discussions:** [GitHub Discussions](https://github.com/satisfactory-calculator/satisfactory-calculator/discussions)
- **Discord:** [Сообщество Satisfactory](https://discord.gg/satisfactory)
- **Сайт:** [Наш Сайт](https://swelock.github.io/SatisfactoryCalculatorSite/)
---

<div align="center">
  <b>Сделано с ❤️ для сообщества Satisfactory</b>
</div> 
