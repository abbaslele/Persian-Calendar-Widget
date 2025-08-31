

# Persian Calendar Widget 📅

A beautiful, lightweight Persian (Jalali) calendar widget built with modern web technologies. This widget provides an elegant and intuitive way to display and interact with the Persian solar calendar system in web applications.

![Persian Calendar Widget](https://img.shields.io/badge/Calendar-Persian-blue) ![License](https://img.shields.io/badge/License-MIT-green) ![Version](https://img.shields.io/badge/Version-1.0.0-orange)

## 🌟 Features

- **📅 Persian Solar Calendar**: Full support for Jalali calendar system with accurate date conversion
- **🎨 Modern UI Design**: Clean, responsive interface with smooth animations
- **📱 Mobile Responsive**: Optimized for desktop, tablet, and mobile devices
- **🌙 Theme Support**: Light and dark theme options
- **🔄 Multiple Views**: Month, week, and day view modes
- **⚡ Lightweight**: Minimal dependencies and fast loading
- **🌐 RTL Support**: Right-to-left layout for Persian text
- **🎯 Easy Integration**: Simple to embed in any web application
- **⚙️ Customizable**: Extensive styling and configuration options
- **🔍 Date Navigation**: Intuitive month/year navigation controls

## 📸 Screenshots

## 🚀 Quick Start

### CDN Installation

```html
<!-- Include CSS -->
<link rel="stylesheet" href="https://cdn.jsdelivr.net/gh/abbaslele/Persian-Calendar-Widget/dist/persian-calendar.min.css">

<!-- Include JavaScript -->
<script src="https://cdn.jsdelivr.net/gh/abbaslele/Persian-Calendar-Widget/dist/persian-calendar.min.js"></script>
```

### NPM Installation

```bash
npm install persian-calendar-widget
```

### Basic Usage

```html
<!DOCTYPE html>
<html lang="fa" dir="rtl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Persian Calendar Widget Demo</title>
    <link rel="stylesheet" href="persian-calendar.css">
</head>
<body>
    <div id="persian-calendar"></div>
    
    <script src="persian-calendar.js"></script>
    <script>
        const calendar = new PersianCalendar('#persian-calendar', {
            theme: 'light',
            view: 'month',
            locale: 'fa',
            showToday: true
        });
    </script>
</body>
</html>
```

## 📖 Documentation

### Initialization

```javascript
// Basic initialization
const calendar = new PersianCalendar('#calendar-container');

// With custom options
const calendar = new PersianCalendar('#calendar-container', {
    theme: 'dark',
    view: 'month',
    locale: 'fa',
    showWeekNumbers: true,
    highlightToday: true,
    animations: true,
    rtl: true
});
```

### Configuration Options

| Option | Type | Default | Description |
|--------|------|---------|-------------|
| `theme` | `string` | `'light'` | Theme mode: `'light'`, `'dark'`, `'auto'` |
| `view` | `string` | `'month'` | Display view: `'month'`, `'vertical-week'`, `'horizontal-week'`, `'day'` |
| `locale` | `string` | `'fa'` | Language locale: `'fa'` (Persian), `'en'` (English) |
| `showWeekNumbers` | `boolean` | `false` | Show week numbers in month view |
| `highlightToday` | `boolean` | `true` | Highlight current date |
| `highlightWeekends` | `boolean` | `true` | Highlight weekend days |
| `animations` | `boolean` | `true` | Enable smooth transitions |
| `rtl` | `boolean` | `true` | Right-to-left layout |
| `showHeader` | `boolean` | `true` | Show calendar header |
| `showNavigation` | `boolean` | `true` | Show navigation buttons |
| `minDate` | `Date` | `null` | Minimum selectable date |
| `maxDate` | `Date` | `null` | Maximum selectable date |
| `selectedDates` | `Array` | `[]` | Pre-selected dates |
| `disabledDates` | `Array` | `[]` | Disabled dates |

### Methods

```javascript
// Navigation methods
calendar.goToToday();                    // Navigate to current date
calendar.goToDate(new Date());           // Navigate to specific date
calendar.nextMonth();                    // Go to next month
calendar.previousMonth();                // Go to previous month
calendar.nextYear();                     // Go to next year
calendar.previousYear();                 // Go to previous year

// View methods
calendar.setView('month');               // Change view mode
calendar.setTheme('dark');              // Change theme
calendar.refresh();                      // Refresh calendar display

// Date methods
calendar.selectDate(new Date());         // Select specific date
calendar.getSelectedDates();             // Get selected dates
calendar.clearSelection();               // Clear all selections

// Utility methods
calendar.destroy();                      // Cleanup and remove widget
calendar.isVisible();                    // Check if calendar is visible
calendar.toggle();                       // Toggle calendar visibility
```

### Events

```javascript
calendar.on('dateSelect', function(date, persianDate) {
    console.log('Selected date:', date);
    console.log('Persian date:', persianDate);
});

calendar.on('monthChange', function(year, month) {
    console.log('Month changed to:', year, month);
});

calendar.on('viewChange', function(newView, oldView) {
    console.log('View changed from', oldView, 'to', newView);
});

calendar.on('themeChange', function(newTheme) {
    console.log('Theme changed to:', newTheme);
});
```

## 🎨 Customization

### CSS Custom Properties

```css
:root {
    /* Colors */
    --pc-primary-color: #2196F3;
    --pc-secondary-color: #FFC107;
    --pc-background-color: #ffffff;
    --pc-text-color: #333333;
    --pc-border-color: #e0e0e0;
    --pc-today-color: #FF5722;
    --pc-selected-color: #4CAF50;
    --pc-weekend-color: #f44336;
    
    /* Typography */
    --pc-font-family: 'IRANSans', 'Tahoma', sans-serif;
    --pc-font-size: 14px;
    --pc-header-font-size: 18px;
    
    /* Spacing */
    --pc-padding: 16px;
    --pc-border-radius: 8px;
    --pc-cell-size: 40px;
    
    /* Animations */
    --pc-transition-duration: 0.3s;
    --pc-transition-timing: ease;
}
```

### Dark Theme

```css
[data-theme="dark"] {
    --pc-background-color: #1e1e1e;
    --pc-text-color: #ffffff;
    --pc-border-color: #404040;
    --pc-primary-color: #64B5F6;
}
```

### Custom Styling Example

```css
.persian-calendar {
    box-shadow: 0 4px 12px rgba(0, 0, 0, 0.15);
    border-radius: 12px;
    overflow: hidden;
}

.persian-calendar .header {
    background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
    color: white;
}

.persian-calendar .day-cell:hover {
    transform: scale(1.1);
    background-color: var(--pc-primary-color);
    color: white;
}
```

## 🌐 URL Parameters

You can customize the widget behavior using URL parameters:

```
https://your-domain.com/calendar?theme=dark&view=month&locale=fa
```

| Parameter | Values | Description |
|-----------|---------|-------------|
| `theme` | `light`, `dark`, `auto` | Set theme mode |
| `view` | `month`, `vertical-week`, `horizontal-week`, `day` | Set initial view |
| `locale` | `fa`, `en` | Set language |

Example URLs:
- `?theme=dark&view=month` - Dark theme with month view
- `?theme=light&view=day` - Light theme with day view
- `?view=vertical-week&locale=en` - Vertical week view in English

## 📱 Responsive Design

The widget automatically adapts to different screen sizes:

- **Desktop**: Full-featured month view with navigation
- **Tablet**: Optimized touch targets and spacing
- **Mobile**: Compact view with swipe gestures
- **Small screens**: Simplified day view for better usability

## 🔌 Integration Examples

### React Integration

```jsx
import { useEffect, useRef } from 'react';
import PersianCalendar from 'persian-calendar-widget';

function CalendarComponent() {
    const calendarRef = useRef(null);
    
    useEffect(() => {
        const calendar = new PersianCalendar(calendarRef.current, {
            theme: 'light',
            view: 'month'
        });
        
        calendar.on('dateSelect', (date) => {
            console.log('Selected:', date);
        });
        
        return () => calendar.destroy();
    }, []);
    
    return <div ref={calendarRef}></div>;
}
```

### Vue.js Integration

```vue
<template>
    <div ref="calendar"></div>
</template>

<script>
import PersianCalendar from 'persian-calendar-widget';

export default {
    mounted() {
        this.calendar = new PersianCalendar(this.$refs.calendar, {
            theme: 'dark',
            view: 'month'
        });
    },
    beforeDestroy() {
        if (this.calendar) {
            this.calendar.destroy();
        }
    }
};
</script>
```

### Angular Integration

```typescript
import { Component, ElementRef, ViewChild, OnInit, OnDestroy } from '@angular/core';
import PersianCalendar from 'persian-calendar-widget';

@Component({
    selector: 'app-calendar',
    template: '<div #calendar></div>'
})
export class CalendarComponent implements OnInit, OnDestroy {
    @ViewChild('calendar', { static: true }) calendarRef!: ElementRef;
    private calendar: any;
    
    ngOnInit() {
        this.calendar = new PersianCalendar(this.calendarRef.nativeElement, {
            theme: 'light',
            view: 'month'
        });
    }
    
    ngOnDestroy() {
        if (this.calendar) {
            this.calendar.destroy();
        }
    }
}
```

## 🛠️ Development

### Prerequisites

- Node.js 14+ and npm
- Modern web browser
- Basic knowledge of HTML, CSS, and JavaScript

### Setup

```bash
# Clone the repository
git clone https://github.com/abbaslele/Persian-Calendar-Widget.git
cd Persian-Calendar-Widget

# Install dependencies
npm install

# Start development server
npm run dev

# Build for production
npm run build

# Run tests
npm test
```

### Project Structure

```
Persian-Calendar-Widget/
├── src/
│   ├── js/
│   │   ├── persian-calendar.js
│   │   ├── date-utils.js
│   │   └── localization.js
│   ├── css/
│   │   ├── persian-calendar.css
│   │   └── themes/
│   └── assets/
│       ├── fonts/
│       └── icons/
├── dist/
│   ├── persian-calendar.min.js
│   └── persian-calendar.min.css
├── examples/
│   ├── basic/
│   ├── react/
│   └── vue/
├── tests/
├── docs/
├── package.json
├── README.md
└── LICENSE
```

## 🧪 Testing

```bash
# Run all tests
npm test

# Run specific test suite
npm run test:unit
npm run test:integration
npm run test:e2e

# Test coverage
npm run test:coverage
```

## 📦 Browser Support

| Browser | Version |
|---------|---------|
| Chrome | 60+ |
| Firefox | 55+ |
| Safari | 12+ |
| Edge | 79+ |
| Opera | 47+ |

## 🤝 Contributing

We welcome contributions! Please see our [Contributing Guide](CONTRIBUTING.md) for details.

### How to Contribute

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

### Development Guidelines

- Follow the existing code style
- Write tests for new features
- Update documentation
- Ensure RTL compatibility
- Test on multiple browsers

## 📋 Roadmap

- [ ] **v1.1.0**: Range selection mode
- [ ] **v1.2.0**: Event management system
- [ ] **v1.3.0**: Multiple calendar support
- [ ] **v1.4.0**: Accessibility improvements
- [ ] **v1.5.0**: Mobile app wrapper
- [ ] **v2.0.0**: Framework-specific packages

## 🐛 Known Issues

- [ ] Safari: Animation lag on older versions
- [ ] Firefox: Font rendering on Linux
- [ ] Edge: Date picker integration

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- Persian calendar algorithms and conversion methods
- Font contributors (IRANSans, Vazir)
- The Persian developer community
- Open source contributors

## 📞 Support & Contact

- 🐛 **Issues**: [GitHub Issues](https://github.com/abbaslele/Persian-Calendar-Widget/issues)
- 💬 **Discussions**: [GitHub Discussions](https://github.com/abbaslele/Persian-Calendar-Widget/discussions)
- 📧 **Email**: [your-email@example.com]
- 🌐 **Website**: [Your website]

## ⭐ Show Your Support

If you find this project helpful, please consider:
- ⭐ Starring the repository
- 🐛 Reporting bugs
- 💡 Suggesting new features
- 🤝 Contributing code
- 📢 Sharing with others

---

**Made with ❤️ for Persian developers worldwide**

<div align="center">
    <img src="https://img.shields.io/github/stars/abbaslele/Persian-Calendar-Widget?style=social" alt="GitHub stars">
    <img src="https://img.shields.io/github/forks/abbaslele/Persian-Calendar-Widget?style=social" alt="GitHub forks">
    <img src="https://img.shields.io/github/watchers/abbaslele/Persian-Calendar-Widget?style=social" alt="GitHub watchers">
</div>
