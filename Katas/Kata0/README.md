Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

Breakdown
- Ordenado? No | Sí
- ¿Qué pasa si no da?
    Debe ser por lo menos 2
- Solo números positicos
- Base Case
    Tamaño sea 2
- Caso
    Buscar complementos

Buscar el complemento del número en el indice actual. Complejidad n².
Hashear todos los elementos junto al índice. Buscar la existencia de complementos. Complejidad n.