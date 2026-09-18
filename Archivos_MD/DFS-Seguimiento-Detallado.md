DFS - Seguimiento
u

Inicialización

tiempo=0

u

v

w

x

y

z

d[]
f[]
p[]
marca[]

blanco blanco blanco blanco blanco blanco

DFS - Seguimiento
u

Descubrimiento de u

tiempo=1

u

d[]

1

v

w

x

y

z

f[]
p[]
marca[]

gris

blanco blanco blanco blanco blanco

DFS - Seguimiento
u

Adyacentes de u

Ady(u)

v, x
tiempo=1

u

d[]

1

v

w

x

y

z

f[]
p[]
marca[]

gris

blanco blanco blanco blanco blanco

DFS - Seguimiento
u

Iteración sobre
Adyacentes de u

Ady(u)

v, x
tiempo=1

u

d[]

1

v

w

x

y

z

f[]
p[]
marca[]

gris

blanco blanco blanco blanco blanco

DFS - Seguimiento
u
v

Elección de
Adyacente de u

Ady(u)

v, x
tiempo=1

u

d[]

1

v

w

x

y

z

f[]
p[]
marca[]

u
gris

blanco blanco blanco blanco blanco

DFS - Seguimiento
u
v

Descubrimiento de v

Ady(u)

v, x
tiempo=2

u

v

d[]

1

2

w

x

y

z

f[]
p[]
marca[]

u
gris

gris

blanco blanco blanco blanco

DFS - Seguimiento
u
v

Adyacentes de v

Ady(u)

v, x

Ady(v)

y

tiempo=2

u

v

d[]

1

2

w

x

y

z

f[]
p[]
marca[]

u
gris

gris

blanco blanco blanco blanco

DFS - Seguimiento
u
v

Iteración sobre
Adyacentes de v

Ady(u)

v, x

Ady(v)

y

tiempo=2

u

v

d[]

1

2

w

x

y

z

f[]
p[]
marca[]

u
gris

gris

blanco blanco blanco blanco

DFS - Seguimiento
u
v

Elección de
Adyacente de v

y

Ady(u)

v, x

Ady(v)

y

tiempo=2

u

v

d[]

1

2

w

x

y

z

f[]
p[]
marca[]

u
gris

gris

v
blanco blanco blanco blanco

DFS - Seguimiento
u
v

Descubrimiento de y

y

Ady(u)

v, x

Ady(v)

y

tiempo=3

u

v

w

x

y

d[]

1

2

3

u

v

z

f[]
p[]
marca[]

gris

gris

blanco blanco

gris

blanco

DFS - Seguimiento
u
v

Adyacentes de y

y

Ady(u)

v, x

Ady(v)

y

Ady(y)

x

tiempo=3

u

v

w

x

y

d[]

1

2

3

u

v

z

f[]
p[]
marca[]

gris

gris

blanco blanco

gris

blanco

DFS - Seguimiento
u
v

Iteración sobre
Adyacentes de y

y

Ady(u)

v, x

Ady(v)

y

Ady(y)

x

tiempo=3

u

v

w

x

y

d[]

1

2

3

u

v

z

f[]
p[]
marca[]

gris

gris

blanco blanco

gris

blanco

DFS - Seguimiento
u
v

Elección de
Adyacente de y

y
x

Ady(u)

v, x

Ady(v)

y

Ady(y)

x

tiempo=3

u

v

d[]

1

2

w

x

y

z

3

f[]
p[]
marca[]

u
gris

gris

y
blanco blanco

v
gris

blanco

DFS - Seguimiento
u
v

Descubrimiento de x

y
x

Ady(u)

v, x

Ady(v)

y

Ady(y)

x

tiempo=4

u

v

d[]

1

w

x

y

2

4

3

u

y

v

gris

gris

z

f[]
p[]
marca[]

gris

gris

blanco

blanco

DFS - Seguimiento
u
v

Adyacentes de x

y
x

Ady(u)

v, x

Ady(v)

y

Ady(y)

x

Ady(x)

v

tiempo=4

u

v

d[]

1

w

x

y

2

4

3

u

y

v

gris

gris

z

f[]
p[]
marca[]

gris

gris

blanco

blanco

DFS - Seguimiento
u
v

Iteración sobre
Adyacentes de x

y
x

Ady(u)

v, x

Ady(v)

y

Ady(y)

x

Ady(x)

v

tiempo=4

u

v

d[]

1

w

x

y

2

4

3

u

y

v

gris

gris

z

f[]
p[]
marca[]

gris

gris

blanco

blanco

DFS - Seguimiento
u
v

Elección de
Adyacente de x

y
x

Ady(u)

v, x

Ady(v)

y

Ady(y)

x

Ady(x)

v

tiempo=4

u

v

d[]

1

w

x

y

2

4

3

u

y

v

gris

gris

z

f[]
p[]
marca[]

gris

gris

blanco

blanco

DFS - Seguimiento
u
v

Finalización de x

y
x

Ady(u)

v, x

Ady(v)

y

Ady(y)

x

Ady(x)

v

tiempo=5

u

v

d[]

1

2

f[]

x

y

4

3

z

5

p[]
marca[]

w

u
gris

gris

y
blanco negro

v
gris

blanco

DFS - Seguimiento
u
v

Retorno a y

y
x

Ady(u)

v, x

Ady(v)

y

Ady(y)

x

Ady(x)

v

tiempo=5

u

v

d[]

1

2

f[]

x

y

4

3

z

5

p[]
marca[]

w

u
gris

gris

y
blanco negro

v
gris

blanco

DFS - Seguimiento
u
v

Itera sobre
Adyacentes
pendientes de y

y
x

Ady(u)

v, x

Ady(v)

y

Ady(y)

x

Ady(x)

v

tiempo=5

u

v

d[]

1

2

f[]

x

y

4

3

z

5

p[]
marca[]

w

u
gris

gris

y
blanco negro

v
gris

blanco

DFS - Seguimiento
u
v

Finalización de y

y
x

Ady(u)

v, x

Ady(v)

y

Ady(y)

x

Ady(x)

v

tiempo=6

u

v

d[]

1

2

f[]
p[]
marca[]

u
gris

gris

w

x

y

4

3

5

6

y

v

z

blanco negro negro blanco

DFS - Seguimiento
u
v

Retorno a v

y
x

Ady(u)

v, x

Ady(v)

y

Ady(y)

x

Ady(x)

v

tiempo=6

u

v

d[]

1

2

f[]
p[]
marca[]

u
gris

gris

w

x

y

4

3

5

6

y

v

z

blanco negro negro blanco

DFS - Seguimiento
u
v

Iteración sobre
Adyacentes pendientes
de v

y
x

Ady(u)

v, x

Ady(v)

y

Ady(y)

x

Ady(x)

v

tiempo=6

u

v

d[]

1

2

f[]
p[]
marca[]

u
gris

gris

w

x

y

4

3

5

6

y

v

z

blanco negro negro blanco

DFS - Seguimiento
u
v

Finalización de v

y
x

Ady(u)

v, x

Ady(v)

y

Ady(y)

x

Ady(x)

v

tiempo=7

u

v

d[]

1

x

y

2

4

3

f[]

7

5

6

p[]

u

y

v

marca[]

gris

w

z

negro blanco negro negro blanco

DFS - Seguimiento
u
v

Retorno a u

y
x

Ady(u)

v, x

Ady(v)

y

Ady(y)

x

Ady(x)

v

tiempo=7

u

v

d[]

1

x

y

2

4

3

f[]

7

5

6

p[]

u

y

v

marca[]

gris

w

z

negro blanco negro negro blanco

DFS - Seguimiento
u
v

Iteración sobre
Adyacentes
pendientes de u

y
x

Ady(u)

v, x

Ady(v)

y

Ady(y)

x

Ady(x)

v

tiempo=7

u

v

d[]

1

x

y

2

4

3

f[]

7

5

6

p[]

u

y

v

marca[]

gris

w

z

negro blanco negro negro blanco

DFS - Seguimiento
u
v

Elección de
Adyacente
pendiente de u

y
x

Ady(u)

v, x

Ady(v)

y

Ady(y)

x

Ady(x)

v

tiempo=7

u

v

d[]

1

x

y

2

4

3

f[]

7

5

6

p[]

u

y

v

marca[]

gris

w

z

negro blanco negro negro blanco

DFS - Seguimiento
u
v

Finalización de u

y
x

Ady(u)

v, x

Ady(v)

y

Ady(y)

x

Ady(x)

v

tiempo=8

u

v

d[]

1

f[]

8

p[]
marca[]

w

x

y

2

4

3

7

5

6

u

y

v

z

negro negro blanco negro negro blanco

DFS - Seguimiento
u
v

Una vez definido f(u),
DFS termina

y
x

Ady(u)

v, x

Ady(v)

y

Ady(y)

x

Ady(x)

v

tiempo=8

u

v

d[]

1

f[]

8

p[]
marca[]

w

x

y

2

4

3

7

5

6

u

y

v

z

negro negro blanco negro negro blanco

DFS - Forest - Seguimiento
u
w
v
y
x

Ady(u)

v, x

Ady(v)

y

Ady(y)

x

Ady(x)

v

tiempo=8

u

v

d[]

1

f[]

8

p[]
marca[]

w

x

y

2

4

3

7

5

6

u

y

v

z

negro negro blanco negro negro blanco

DFS - Forest - Seguimiento
u
w
v

Descubrimiento de w

y
x

Ady(u)

v, x

Ady(v)

y

Ady(y)

x

Ady(x)

v

tiempo=9

u

v

w

x

y

d[]

1

2

9

4

3

f[]

8

7

5

6

u

y

v

p[]
marca[]

negro negro

gris

z

negro negro blanco

DFS - Forest - Seguimiento
u
w
v

Adyacentes de w

y
x

Ady(u)

v, x

Ady(v)

y

Ady(y)

x

Ady(x)

v

p[]

Ady(w)

y, z

marca[]

tiempo=9

u

v

w

x

y

d[]

1

2

9

4

3

f[]

8

7

5

6

u

y

v

negro negro

gris

z

negro negro blanco

DFS - Forest - Seguimiento
u
w
v

Iteración sobre
Adyacentes de w

y
x

Ady(u)

v, x

Ady(v)

y

Ady(y)

x

Ady(x)

v

p[]

Ady(w)

y, z

marca[]

tiempo=9

u

v

w

x

y

d[]

1

2

9

4

3

f[]

8

7

5

6

u

y

v

negro negro

gris

z

negro negro blanco

DFS - Forest - Seguimiento
u
w
v

Elección de
Adyacente de w

y
x

Ady(u)

v, x

Ady(v)

y

Ady(y)

x

Ady(x)

v

p[]

Ady(w)

y, z

marca[]

tiempo=9

u

v

w

x

y

d[]

1

2

9

4

3

f[]

8

7

5

6

u

y

v

negro negro

gris

z

negro negro blanco

DFS - Forest - Seguimiento
u
w
v

Elección de
Adyacente de w

z
y
x

Ady(u)

v, x

Ady(v)

y

Ady(y)

x

Ady(x)

v

p[]

Ady(w)

y, z

marca[]

tiempo=9

u

v

w

x

y

d[]

1

2

9

4

3

f[]

8

7

5

6

u

y

v

negro negro

gris

z

w

negro negro blanco

DFS - Forest - Seguimiento
u
w
v

Descubrimiento de z

z
y
x

Ady(u)

v, x

Ady(v)

y

Ady(y)

x

Ady(x)

v

p[]

Ady(w)

y, z

marca[]

tiempo=10

u

v

w

x

y

z

d[]

1

2

9

4

3

10

f[]

8

7

5

6

u

y

v

negro negro

gris

negro negro

w
gris

DFS - Forest - Seguimiento
u
w
v

Adyacentes de z

z
y
x

Ady(u)

v, x

Ady(v)

y

Ady(y)

tiempo=10

u

v

w

x

y

z

x

d[]

1

2

9

4

3

10

Ady(x)

v

f[]

8

7

5

6

Ady(w)

y, z

p[]

u

y

v

Ady(z)

z

marca[]

negro negro

gris

negro negro

w
gris

DFS - Forest - Seguimiento
u
w
v

Iteración sobre
adyacentes de z

z
y
x

Ady(u)

v, x

Ady(v)

y

Ady(y)

tiempo=10

u

v

w

x

y

z

x

d[]

1

2

9

4

3

10

Ady(x)

v

f[]

8

7

5

6

Ady(w)

y, z

p[]

u

y

v

Ady(z)

z

marca[]

negro negro

gris

negro negro

w
gris

DFS - Forest - Seguimiento
u
w
v

Elección de
adyacente de z

z
y
x

Ady(u)

v, x

Ady(v)

y

Ady(y)

tiempo=10

u

v

w

x

y

z

x

d[]

1

2

9

4

3

10

Ady(x)

v

f[]

8

7

5

6

Ady(w)

y, z

p[]

u

y

v

Ady(z)

z

marca[]

negro negro

gris

negro negro

w
gris

DFS - Forest - Seguimiento
u
w
v

Finalización de z

z
y
x

Ady(u)

v, x

Ady(v)

y

Ady(y)

tiempo=11

u

v

w

x

y

z

x

d[]

1

2

9

4

3

10

Ady(x)

v

f[]

8

7

5

6

11

Ady(w)

y, z

p[]

u

y

v

w

Ady(z)

z

marca[]

negro negro

gris

negro negro negro

DFS - Forest - Seguimiento
u
w
v

Retorno a w

z
y
x

Ady(u)

v, x

Ady(v)

y

Ady(y)

tiempo=11

u

v

w

x

y

z

x

d[]

1

2

9

4

3

10

Ady(x)

v

f[]

8

7

5

6

11

Ady(w)

y, z

p[]

u

y

v

w

Ady(z)

z

marca[]

negro negro

gris

negro negro negro

DFS - Forest - Seguimiento
u
w
v

Finalización de w

z
y
x

Ady(u)

v, x

Ady(v)

y

Ady(y)

tiempo=12

u

v

w

x

y

z

x

d[]

1

2

9

4

3

10

Ady(x)

v

f[]

8

7

12

5

6

11

Ady(w)

y, z

p[]

y

v

w

Ady(z)

z

marca[]

u

negro negro negro negro negro negro

DFS - Forest - Seguimiento
u
w
v

Una vez definido f(w),
DFS Forest termina

z
y
x

Ady(u)

v, x

Ady(v)

y

Ady(y)

tiempo=12

u

v

w

x

y

z

x

d[]

1

2

9

4

3

10

Ady(x)

v

f[]

8

7

12

5

6

11

Ady(w)

y, z

p[]

y

v

w

Ady(z)

z

marca[]

u

negro negro negro negro negro negro

