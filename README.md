# IwTween

A minimal header-only C++ tween library

## Example Usage

```cpp
#include <iostream>

#include "iwtween.h"

int main()
{
    float alpha = 0.0f;

    iw::Tween<float> tween{ 0.0f, 100.0f };

    bool isRunning = true;
    while (isRunning) {
        // Calculate delta time here

        alpha += deltaTime;

        std::cout << tween.at(alpha, iw::Tween<float>::easeInCubicInterp) << std::endl;

        if (alpha >= 1.0f)
            isRunning = false;
    }

    return 0;
}
```

## Features

- Header-only
- No external dependencies (only depends on standard libary)
- Supports every type which implements `+`, `-` and `*`
- Doesn't run its own loop, use your existing app/game loop
- Various interpolation methods
  - Feel free to contribute more as many interpolation methods are currently missing!

## Contributing

I'll be updating this library as I need to for personal projects, however, contributions are very welcome!

## License

IwTween is released under the MIT license. See [LICENSE](./LICENSE) for more details
