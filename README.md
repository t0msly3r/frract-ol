# fract-ol

Proyecto de la escuela 42 que renderiza fractales matemáticos de forma interactiva usando la biblioteca gráfica **MLX42** (OpenGL + GLFW). Permite explorar los conjuntos de Mandelbrot, Julia y Burning Ship con zoom, desplazamiento y cambio de color en tiempo real.

---

## Fractales disponibles

| Nº | Fractal | Descripción |
|----|---------|-------------|
| `1` | **Mandelbrot** | El fractal más famoso. Itera `z = z² + c` partiendo de `z = 0` |
| `2` | **Julia** | Variante de Mandelbrot con `c` fijo y `z` variable. Admite parámetros personalizados |
| `3` | **Burning Ship** | Variante que aplica valor absoluto antes de elevar al cuadrado, creando formas de barco en llamas |

---

## Dependencias

- **MLX42** — biblioteca gráfica basada en OpenGL, incluida en `lib/mlx42/`
- **GLFW** — sistema de ventanas requerido por MLX42 (`-lglfw`)
- **libft** — librería de funciones propias, incluida en `lib/libft/`

### Instalar GLFW (si no está disponible)

```bash
# Ubuntu/Debian
sudo apt install libglfw3-dev

# macOS
brew install glfw
```

### Compilar MLX42 (necesario la primera vez)

```bash
cd lib/mlx42
cmake -B build
cmake --build build -j4
cd ../..
```

---

## Compilación

```bash
make        # Compila el ejecutable fractol
make clean  # Elimina los objetos
make fclean # Elimina objetos y el ejecutable
make re     # Recompila desde cero
```

---

## Uso

```bash
./fractol <número_fractal> [param_real param_imaginario]
```

```bash
# Mandelbrot
./fractol 1

# Julia con parámetros por defecto (-0.4, 0.6)
./fractol 2

# Julia con parámetros personalizados
./fractol 2 -0.7 0.27

# Burning Ship
./fractol 3
```

Si se ejecuta sin argumentos o con un argumento inválido, el programa muestra el menú:

```
1... Mandelbrot
2... Julia
3... Burningship
```

---

## Controles

| Tecla / Acción | Efecto |
|----------------|--------|
| `Scroll arriba` | Zoom in (centrado en el cursor) |
| `Scroll abajo` | Zoom out |
| `←` `→` `↑` `↓` | Desplazar la vista |
| `C` | Cambiar el esquema de color |
| `ESC` | Cerrar la ventana |

El zoom adapta automáticamente las iteraciones máximas para mantener el detalle al acercar y optimizar el rendimiento al alejar.

---

## Implementación

### Mapeo de píxeles

Cada píxel `(x, y)` de la ventana se convierte a coordenadas del plano complejo mediante:

```
c.x = middle.x + 2 * range * (x / WIDTH  - 0.5)
c.y = middle.y + 2 * range * (y / HEIGHT - 0.5)
```

Donde `middle` es el centro de la vista y `range` el nivel de zoom.

### Coloreado

El color de cada píxel depende del número de iteraciones que tardó en escapar (divergir). Los píxeles que nunca escapan se pintan de negro. El valor `color` actúa como multiplicador del índice de iteración y se puede ajustar con `C`.

### Zoom inteligente

Al hacer zoom in, el nuevo centro se desplaza hacia el punto bajo el cursor para que el zoom resulte natural. Al hacer zoom out, el centro se aleja del cursor en la dirección opuesta.

---

## Estructura del proyecto

```
fract-ol/
├── include/
│   └── fractol.h        # Structs t_complex y t_fractal, prototipos
├── lib/
│   ├── mlx42/           # Biblioteca gráfica MLX42
│   └── libft/           # Librería de funciones propias
└── src/
    ├── main.c           # Entrada, inicialización y registro de hooks
    ├── fractal.c        # Algoritmos de Mandelbrot, Julia y Burning Ship
    ├── hooks.c          # Gestión de teclado, ratón y scroll
    └── utils.c          # map, cleanup, ft_atoi, ft_atof, ft_strlen
```

---

## Autor

**tfiz-ben** — estudiante de 42
