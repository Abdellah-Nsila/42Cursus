# Complex numbers

 - So lets look to power of a number: pow(4) = 16, pow(2) = 4, pow(-2) = 4, pow(-1) = 1
 - Cool but lets try the sqrt of a number: sqrt(16) = 4, sqrt(4) = 2, sqrt(-1) Ok thats intersting the sqrt of an negative number is not existing because the power of a negative number is always a positive number so we consider `i^2 = -1`.
 - So can you imagine a value of sqrt(-1)? because you can imagine let's called `i` (imaginary number) thats it, now we have create a new type of numbers the imaginary numbers it's also include all real numbers in his domaine.
 - Now imagie an axe (line), the middle of this axe we have `0`, right of this axe we have all positive numbers, on left we have all negative numbers, yes this is the x-axis, its containe only the real numbers (5, 0, -15, 1/3 2.78, sqrt(2), ...).
 - But what about imaginary numbers? in simple term this is the y-axis, but insted of having numbers like this (-5, 0, 1, 66), we have like this (-5i, 0i, 1i, 66i) if you have a good imagination skills you know that we have a `2D plan`.
 - An imaginary number is a combinision between two part an real part (x-axis) and imaginary part (y-axis); Complex number notation: `x + yi` which `x` is the real cmponent, and `yi` is the imaginary component, in docs you see this format `a + bi` its same btw, and the Complex number describe a point in the 2D plan.
 - Finaly you must know that the complex number is a coordinate of an point in 2D plan wich useful to use in our programme so now we can implement a `Complex plan (2D plan)` in any graphique window and control pixels like a point in a 2D plan with his own complex number (coordinate).

# Complex Plan3

 - Basicaly is the 2D plan XD, x-axis and y-axis
 - Which the x-axis represent the real numbers, and the y-axis represent the imaginary numbers

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
 - Finally we need just to calculate the real part and imaginary part, and add them, and check if the result diverge to inifity, because we dont have time to wait to infinity we just take a value like `4` to check if its greater or smaller than,if it is smaller we color on black, otherwise we color usig diffrent color to set a depth to diverge