## C++ Coding Style Conventions
| Code element | Convention | Example |
| ------------ | :---------:| ------- |
| Variables | lowerCase | `int myVariable` |
| Boolean variables | bTitleCase | `bool bIsActive = false` |
| Pointers | Type* pointer | `Texture* myTexture = nullptr` |
| Operators | value1 + value2 | `int sum = value1 + value 2` |
| Enum | TitleCase | `enum ErrType` |
| Enum members | ALL_CAPS | `WARNING` |
| Class | TitleCase | `ResourceEngine` |
| Class members | m_lowerCase | `m_window` |
| Functions | lowerCase | `void setTitle(const std::string& title)` |
| Functions params | lowerCase | `width`, `hight` |

- Use tabs with 4 width

- When dealing with braces or curly brackets, open-close them in aligned mode:
```
void someFunc()
{

}
```

- Keep switch-case in this way:
```
switch (value)
{
	case 0:
	{
		// do something big..	
		break;
	}
	case 1: /* do something little.. */ break;
	default: break;
}
```

- Control flow statements always are folowed by a space: 
```
if (condition) value = 0

while (!bIsActive)
{

}

for (int i = 0; i < 10; i++) std::cout << i << std::endl;

switch (value)
{
	case 0:
	{
		// do something big..	
		break;
	}
	case 1: /* do something little.. */ break;
	default: break;
}
```

## Files and Directories Naming Conventions
### Directories
- Directories in src and include will be named using **TitleCase**: `Core/` `Utils/`
- Directories outside src and include will be named using **snake_case**: `docs/` `assets/`

### Files
- Files in src and include will be named using **TitleCase** with their appropriate class names: `Engine`, `Window`
- Files outside src and include will be named using **snake_case**: `logo.png`
- Files with .md extension will be named using **ALL_CAPS**: `CONVENTIONS.md`, `README.md`