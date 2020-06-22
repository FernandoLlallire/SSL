### GetLength
GetLength : Σ* -> N / GetLength(string) = { 0 si string='/0' { GetLength(string) +1 si string = string * w AND w ∈ Σ* 
### IsEmpty
IsEmpty : Σ* -> Bool / IsEmpty(string) = { True si String = '/0' { False si String != '/0'
### Power
Power : Σ* x N -> Σ* / Power(string_1,n) = { '/0' si n=0 {string si n=1 {string_1*Power(string_1, n-1) si string!= null
### Concat
Concat : Σ* x Σ* -> Σ* / Concat(string_1,string_2) = {string_1 +string2}