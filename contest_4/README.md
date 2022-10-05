## Contest_4

### A_zero

Ввод-вывод сделан за Вас. От Вас требуется только написать одну или несколько ассемблерных команд.
Никакие заголовки, функции, кавычки и \n не нужны.

С помощью ассемблерной команды обнулите то, что лежит в регистре x0.

### B_one

С помощью ассемблерной команды установите в регистр x0 единицу.

### C_next

С помощью ассемблерной команды увеличьте число в регистре w0 на единицу.
При этом портить старшую часть регистра x0 нельзя.

### D_prev

С помощью ассемблерной команды уменьшите число в регистре w0 на единицу.
При этом портить старшую часть регистра x0 нельзя.

### E_sum

За суп молочный - рупь!

За пудинг сочный - два!

И вышло ровно - три!

С вас шесть рублей!

К сожалению, с приходом online-касс пришлось сказать ей "go away or I will replace you with a simple shell script". Ваша задача - написать программу, которая будет корректно складывать числа.
(32-битная версия)

Сложите 32-битные регистры w1 и w2, результат поместите в w3.
Остальные регистры портить нельзя.

### F_sum64

Времена меняются, происходит инфляция. В 32 бита стоимость блюд в столовой Физтеха уже не влезает. Пора писать новую версию

(64-битная версия)

Сложите 64-битные регистры x1 и x2, результат поместите в x3.
Остальные регистры портить нельзя.

Сравните по тестам, что будет, если вместо 64-битных взять 32-битные регистры w1, w2 и w3 соответственно.

### G_sub

Найдите разницу x1 и x2, результат поместите в x3.
Остальные регистры портить нельзя.

### H_mul

(32-битная версия)

Перемножьте 32-битные регистры w1 и w2, результат поместите в w3.
Остальные регистры портить нельзя.

Сравните по тестам, что будет, если вместо 32-битных взять 64-битные регистры x1, x2 и x3 соответственно.

### I_mul64

(64-битная версия)

Перемножьте 64-битные регистры x1 и x2, результат поместите в x3.
Остальные регистры портить нельзя.

Сравните по тестам, что будет, если вместо 64-битных взять 32-битные регистры w1, w2 и w3 соответственно.

### J_sdiv

(32-битная версия)

Разделите 32-битные регистры w1 на w2, результат поместите в w3.
Остальные регистры портить нельзя.

Сравните по тестам, что будет, если вместо 32-битных взять 64-битные регистры x1, x2 и x3 соответственно.

### K_sdiv64

(64-битная версия)

Разделите 64-битные регистры x1 на x2, результат поместите в x3.
Остальные регистры портить нельзя.

Сравните по тестам, что будет, если вместо 64-битных взять 32-битные регистры w1, w2 и w3 соответственно.

### L_egalite

(32-битная версия)

Равны ли числа в 32-битных регистрах w1 и w2? Если да, выведите в w3 единицу, иначе 0.
Остальные регистры портить нельзя.

Сравните по тестам, что будет, если вместо 32-битных взять 64-битные регистры x1, x2 и x3 соответственно.

### M_egalite64

(64-битная версия)

Равны ли числа в 64-битных регистрах x1 и x2? Если да, выведите в x3 единицу, иначе 0.
Остальные регистры портить нельзя.

Сравните по тестам, что будет, если вместо 64-битных взять 32-битные регистры w1, w2 и w3 соответственно.

### N_Factorial

(32-битная версия)

Ограничение по времени работы программы: 1 секунда.
Ограничение по памяти: только регистры процессора.
Ввод в регистре w1[7:0].
Вывод в регистре w2.

w2 = w1.b0!

Вычислите факториал числа, лежащего в младшем байте регистра w1, результат верните через w2.
Разрешается пользоваться любыми регистрами процессора.

### O_Factorial64

(64-битная версия)

Ограничение по времени работы программы: 1 секунда.
Ограничение по памяти: только регистры процессора.
Ввод в регистре x1[7:0].
Вывод в регистре x2.

x2 = x1.b0!

Вычислите факториал числа, лежащего в младшем байте регистра x1, результат верните через x2.
Разрешается пользоваться любыми регистрами процессора.

### P_AntiFa

Найдите положительное число, факториал которого лежит в регистре w1. Результат верните через регистр w2.

Разрешается пользоваться любыми регистрами процессора.

### Q_AntiFa64

Найдите положительное число, факториал которого лежит в регистре x1. Результат верните через регистр x2.

Разрешается пользоваться любыми регистрами процессора.

### R_gcd

Найти наибольший общий делитель (НОД) двух чисел, содержащихся в регистрах w1 и w2. Результат оставьте в регистре w1.

### S_vector

Disclaimer: 64-bit ARMv8 only currently is supported.

Ассистент Аркадий Артурович Антифакториалов читал аналитическую геометрию. Он решил преподавать по-современному: пусть студенты не решают задачи в тетрадях, а напишут алгоритм их решения на каком-либо языке программирования. Естественно, Аркадий Артурович выбрал Ассемблер... и, подверженный новым веяниям моды, решил дать своим студентам полную свободу выбирать компилятор и разрядность архитектуры. Свобода, разумеется, ограничивалась рамками семейства процессоров ARM (v7 или v8).

В регистре x1 (или, для 32 бит, r1) лежит адрес начала массива.

В регистре x2 (или, соответственно, r2) лежит количество элементов массива.

В регистр x3 (или, соответственно, r3) положите сумму элементов массива.

В массиве лежат 32- или 64-битные целые числа, в зависимости от выбранной архитектуры.