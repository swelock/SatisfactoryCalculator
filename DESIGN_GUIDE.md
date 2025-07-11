# 🎨 Satisfactory Calculator Pro - Design Guide

## Концепция дизайна

Новый дизайн приложения вдохновлен современными веб-интерфейсами 2025 года и сочетает в себе:

### 🌟 Ключевые принципы
- **Glassmorphism** - стеклянные эффекты с размытием
- **Modern Gradients** - многослойные градиенты
- **Card-based Layout** - карточный дизайн
- **Micro-interactions** - тонкие анимации
- **Typography Hierarchy** - четкая типографическая иерархия

### 🎨 Цветовая палитра

#### Основные цвета
- **Primary**: `#6366f1` (Indigo 500)
- **Primary Dark**: `#4f46e5` (Indigo 600)
- **Background**: `#0a0e27` → `#2a2f4a` (Gradient)
- **Surface**: `rgba(15, 23, 42, 0.8)` (Slate 900 + Alpha)

#### Текстовые цвета
- **Primary Text**: `#f1f5f9` (Slate 100)
- **Secondary Text**: `#e2e8f0` (Slate 200)
- **Muted Text**: `#94a3b8` (Slate 400)

#### Акцентные цвета
- **Success**: `#22d3ee` (Cyan 400)
- **Warning**: `#fbbf24` (Amber 400)
- **Error**: `#ef4444` (Red 500)
- **Info**: `#34d399` (Emerald 400)

### 🔧 Компоненты

#### Кнопки
```css
background: qlineargradient(
    stop:0 rgba(99, 102, 241, 0.8), 
    stop:1 rgba(79, 70, 229, 0.9)
);
border-radius: 12px;
padding: 12px 24px;
font-weight: 600;
```

#### Поля ввода
```css
background: rgba(30, 41, 59, 0.7);
border: 2px solid rgba(71, 85, 105, 0.3);
border-radius: 10px;
backdrop-filter: blur(10px);
```

#### Карточки
```css
background: rgba(15, 23, 42, 0.8);
border: 1px solid rgba(71, 85, 105, 0.2);
border-radius: 16px;
padding: 20px;
```

### 📱 Адаптивность

#### Размеры окна
- **Минимальный**: 1200x800px
- **Рекомендуемый**: 1600x1000px
- **Максимальный**: без ограничений

#### Брейкпоинты
- **Desktop Large**: 1600px+
- **Desktop**: 1200px+
- **Tablet**: 768px+
- **Mobile**: 480px+

### 🎭 Анимации и эффекты

#### Hover эффекты
- Изменение цвета: 200ms ease
- Трансформация: transform translateY(-1px)
- Изменение тени: box-shadow

#### Фокус состояния
- Подсветка границ: border-color transition
- Изменение фона: background transition
- Outline: none (кастомная подсветка)

### 🏗️ Архитектура интерфейса

```
MainWindow
├── Header Card
│   ├── Title & Icon
│   ├── Subtitle
│   └── Version Badges
└── Tab Widget
    ├── 🚀 Космический лифт
    ├── 🏗️ HUB обновления  
    ├── ⚙️ Пользовательские расчеты
    └── 🔄 Альтернативные рецепты
```

### 📊 Типографика

#### Шрифты
- **Primary**: 'Inter', 'Segoe UI', 'Roboto', sans-serif
- **Weights**: 400 (Regular), 500 (Medium), 600 (SemiBold), 700 (Bold)

#### Размеры
- **H1 (Title)**: 24px, weight: 700
- **H2 (Subtitle)**: 18px, weight: 600
- **Body**: 14px, weight: 500
- **Caption**: 12px, weight: 500
- **Small**: 11px, weight: 400

### 🎯 UX принципы

#### Доступность
- Высокий контраст текста
- Четкие фокус-состояния
- Логическая навигация
- Поддержка клавиатуры

#### Производительность
- Lazy loading альтернативных рецептов
- Кэширование расчетов
- Оптимизированные градиенты
- Минимальные анимации

#### Удобство использования
- Интуитивная навигация
- Быстрый доступ к функциям
- Информативные тултипы
- Визуальная обратная связь

### 🔧 Технические детали

#### Qt Stylesheets
- Использование rgba() для прозрачности
- qlineargradient для градиентов
- border-radius для скругления
- font-family для типографики

#### Компоненты
- QTabWidget для вкладок
- QTreeWidget для результатов
- QSplitter для разделения
- QScrollArea для прокрутки

### 🚀 Будущие улучшения

#### Планируемые функции
- [ ] Темная/светлая тема
- [ ] Настраиваемые цвета
- [ ] Анимации переходов
- [ ] Экспорт в различные форматы
- [ ] Интеграция с игрой

#### Оптимизации
- [ ] Векторные иконки
- [ ] Улучшенная производительность
- [ ] Мобильная версия
- [ ] Веб-версия

---

*Дизайн создан с учетом современных тенденций UI/UX 2025 года* 