# Complex numbers

 - So lets look to power of a number: pow(4) = 16, pow(2) = 4, pow(-2) = 4, pow(-1) = 1
 - Cool but lets try the sqrt of a number: sqrt(16) = 4, sqrt(4) = 2, sqrt(-1) Ok thats intersting the sqrt of an negative number is not existing because the power of a negative number is always a positive number so we consider `i^2 = -1`.
 - So can you imagine a value of sqrt(-1)? because you can imagine let's called `i` (imaginary number) thats it, now we have create a new type of numbers the imaginary numbers it's also include all real numbers in his domaine.
 - Now imagie an axe (line), the middle of this axe we have `0`, right of this axe we have all positive numbers, on left we have all negative numbers, yes this is the x-axis, its containe only the real numbers (5, 0, -15, 1/3 2.78, sqrt(2), ...).
 - But what about imaginary numbers? in simple term this is the y-axis, but insted of having numbers like this (-5, 0, 1, 66), we have like this (-5i, 0i, 1i, 66i) if you have a good imagination skills you know that we have a `2D plan`.
 - An imaginary number is a combinision between two part an real part (x-axis) and imaginary part (y-axis); Complex number notation: `x + yi` which `x` is the real cmponent, and `yi` is the imaginary component, in docs you see this format `a + bi` its same btw, and the Complex number describe a point in the 2D plan.
 - Finaly you must know that the complex number is a coordinate of an point in 2D plan wich useful to use in our programme so now we can implement a `Complex plan (2D plan)` in any graphique window and control pixels like a point in a 2D plan with his own complex number (coordinate).

# Complex Plan

 - Basicaly is the 2D plan XD, x-axis and y-axis
 - Which the x-axis represent the real numbers, and the y-axis represent the imaginary numbers


# How window (pixel space) is mapped to a 2D logical plane (custom dimension)

`To understand how the window (pixel space) is mapped to a 2D logical plane (custom dimension), let’s break it down step by step. This explanation will also include how each pixel (x, y) in the window corresponds to a point (logical_x, logical_y) in the 2D logical plane.`

## Window (Pixel Space)

    The window is a grid of pixels with dimensions width x height. Each pixel has coordinates (x, y), where:

    x ranges from 0 to width - 1 (left to right).
    y ranges from 0 to height - 1 (top to bottom).


    For example, if the window is `800x600`:

    The top-left corner is (0, 0).
    The bottom-right corner is (799, 599).

### 2D Logical Plane (Custom Dimension)

    The 2D logical plane is a custom coordinate system defined by (min_x, max_x, min_y, max_y). This plane can represent any range of values, such as:

    min_x = -2.0, max_x = 2.0
    min_y = -1.5, max_y = 1.5
    
    This allows you to map the pixel space to a custom range of values, `which is useful for rendering fractals, graphs, or other mathematical visualizations`.

### Mapping Pixel Space to Logical Space

    To map a pixel (x, y) to a point (logical_x, logical_y) in the 2D logical plane, we use the following formulas:

    logical_x = min_x + (x / width) × (max_x − min_x)
    logical_y = min_y + (y / height) × (max_y − min_y)

#### Explanation:

    * `x / width` gives the normalized position of the pixel along the x-axis (ranging from 0 to 1).

    * Multiplying by `(max_x - min_x)` scales this normalized value to the range of the logical plane.

    * Adding min_x shifts the value to the correct position in the logical plane.

    * The same logic applies for logical_y.

### Example Mapping
    Let’s say:

    Window dimensions: width = 800, height = 600
    Logical plane: min_x = -2.0, max_x = 2.0, min_y = -1.5, max_y = 1.5

 #### Mapping the Top-Left Corner (0, 0):
    logical_x = −2.0+(0800)×(2.0−(−2.0)) = −2.0
    logical_x = −2.0+(8000​)×(2.0−(−2.0)) = −2.0
    logical_y = −1.5+(0600)×(1.5−(−1.5)) = −1.5
    logical_y = −1.5+(6000​)×(1.5−(−1.5)) = −1.5

    So, (0, 0) in pixel space maps to (-2.0, -1.5) in the logical plane.

 #### Mapping the Bottom-Right Corner (799, 599):
    logical_x = −2.0+(799800)×(2.0−(−2.0)) ≈ 2.0
    logical_x = −2.0+(800799​)×(2.0−(−2.0)) ≈ 2.0
    logical_y = −1.5+(599600)×(1.5−(−1.5)) ≈ 1.5
    logical_y = −1.5+(600599​)×(1.5−(−1.5)) ≈ 1.5

    So, (799, 599) in pixel space maps to (2.0,  1.5) in the logical plane.

 #### Mapping the Center (400, 300):
    logical_x = −2.0+(400800)×(2.0−(−2.0)) = 0.0
    logical_x = −2.0+(800400​)×(2.0−(−2.0)) = 0.0
    logical_y = −1.5+(300600)×(1.5−(−1.5)) = 0.0
    logical_y = −1.5+(600300​)×(1.5−(−1.5)) = 0.0

    So, (400, 300) in pixel space maps to (0.0, 0.0) in the logical plane.

 ### Here’s a simple ASCII representation of how the pixel space maps to the logical plane:
``` plainText
Pixel Space (800x600)          Logical Plane (min_x=-2.0, max_x=2.0, min_y=-1.5, max_y=1.5)
+-------------------------+    +-------------------------+
| (0,0)                   |    | (-2.0, 1.5)             |
|                         |    |                         |
|                         |    |                         |
|                         |    |                         |
|                         |    |                         |
|                         |    |                         |
|                         |    |                         |
| (400,300)               |    | (0.0, 0.0)              |
|                         |    |                         |
|                         |    |                         |
|                         |    |                         |
|                         |    |                         |
|                         |    |                         |
|                         |    |                         |
| (799,599)               |    | (2.0, -1.5)             |
+-------------------------+    +-------------------------+
```

#### Zooming in the Logical Plane

    When you zoom in or out, you adjust the min_x, max_x, min_y, and max_y values to focus on a smaller or larger region of the logical plane. For example:

        Zooming in by a factor of 2 would halve the range of min_x, max_x, min_y, and max_y.

        Zooming out by a factor of 2 would double the range.

The ft_zoom_square_plane function adjusts these values based on the mouse position and zoom factor:
c
Copy

``` C
void ft_zoom_plane(t_fractol *fractol, double zoom_factor, int mouse_x, int mouse_y)
{
    // Convert mouse coordinates to logical space
    double mouse_x_logical = fractol->min_x + (mouse_x / (double)fractol->width) * (fractol->max_x - fractol->min_x);
    double mouse_y_logical = fractol->min_y + (mouse_y / (double)fractol->height) * (fractol->max_y - fractol->min_y);

    // Adjust the min/max coordinates
    fractol->min_x = mouse_x_logical + (fractol->min_x - mouse_x_logical) / zoom_factor;
    fractol->max_x = mouse_x_logical + (fractol->max_x - mouse_x_logical) / zoom_factor;
    fractol->min_y = mouse_y_logical + (fractol->min_y - mouse_y_logical) / zoom_factor;
    fractol->max_y = mouse_y_logical + (fractol->max_y - mouse_y_logical) / zoom_factor;
}
```

7. Summary

    The pixel space (x, y) is mapped to the logical plane (logical_x, logical_y) using linear interpolation.

    The logical plane can represent any custom range of values, allowing for flexible visualization.

    Zooming adjusts the min_x, max_x, min_y, and max_y values to focus on a specific region of the logical plane.

This approach is commonly used in fractal rendering, graphing, and other applications where you need to map pixel coordinates to a custom coordinate system.

 # Mandelbrot set

 - The `Mandelbrot set` is a two-dimensional set with a relatively simple definition that exhibits great complexity, especially as it is magnified. It is popular for its aesthetic appeal and fractal structures. The set is defined in the complex plane as the complex numbers `c`,
 - for which the function `f(z) = z^2 + c` does not diverge to infinity when iterated starting at `z = 0` , i.e., for which the sequence `f(0)`, `f(f(0))`, etc., remains bounded in absolute value.
 - We see that the representation of the `Mandelbrot set` is a recursive function => `f(z) = z^2 + c`, that call hitself starting at `z = 0`, and his utput is the input of the next call for example:
 - We have `z = 0`, and `c = 0`, let's apply this function recursively `f(z) = z^2 + c`:
 - `f(0) = 0^2 + 1` => `f(0) = 1` | `f(1) = 1^2 + 1` => `f(1) = 2` | `f(2) = 2^2 + 1` => `f(2) = 5` | `f(5) = 5^2 + 1` => `f(5) = 26` | `f(26) = 26^2 + 1` => `f(26) = 677` you can see the function diverge to infinity
 - Now We have `z = 0`, and `c = -1`, let's apply this function recursively `f(z) = z^2 + c`:
 - `f(0) = 0^2 - 1` => `f(0) = -1` | `f(-1) = -1^2 - 1` => `f(-1) = 0` | `f(0) = 0^2 - 1` => `f(0) = -1` | `f(-1) = -1^2 - 1` => `f(-1) = 0` you can see here the function does not diverge it stay in a loop
 - So know we have two senarios when given parametres to the `f(z) = z^2 + c`, if the function does not diverge is part of `Mandelbrot set`, if not, it'is not Xd 

# Instruction from math

 - `f(z) = z^2 + c` with `z0 = 0`, `c = a + bi` (`c` is a complex number)
 - `f(z1) = c`
 - `f(z2) = z1^2 + c`
 - `f(z2) = c^2 + c`
 - `f(z2) = c^2 + c`
 - let's take `c^2` first, we know that `c = a + bi`
 - `c^2` = `(a+bi) * (a+bi)`
 - `c^2` = `a^2 + abi + abi + (b^2 * i^2)` we know that `i^2 = -1`
 - `c^2` = `a^2 + abi + abi + (b^2 * -1)`
 - `c^2` = `a^2 + abi + abi + (-b^2)`
 - `c^2` = `a^2 + abi + abi - b^2`
 - `c^2` = `a^2 + 2abi - b^2`
 - `c^2` = `a^2 - b^2 + 2abi`
 - `c^2` = `(a^2 - b^2) + 2abi` now our expression containe two part real part and imaginary part
 - let's take `c` andto expression
 - `f(z2) = (a^2 - b^2) + 2abi + a + bi`
 - `f(z2) = (a^2 - b^2 + a) + 2abi + bi`
 - real part:     `(a^2 - b^2 + a)`
 - imaginary part: `2abi + bi`
 
 ## Comdition in code
 - Finally we need just to calculate the real part and imaginary part, and add them, and check if the result diverge to inifity, because we dont have time to wait to infinity we just take a value like `4` to check if its greater or smaller than,if it is smaller we color on black, otherwise we color using diffrent color to show depth variant

 # Zoom behavioure
 - The key is to set a dimension to you plan , create a plan and zoom in/out