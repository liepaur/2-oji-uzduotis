# 1-oji-uzduotis
Testavimas

Testavimo sistemos parametrai:

1. CPU: Apple M4
2. RAM: 16GB
3. HDD: SSD

| Elementų skaičius | Rūšiavimas (s) | Kietiakų spausd. (s) | Vargsiukų spausd. (s) | Įrašymas į failus (s) | Visa programa (s) |
| ----------------: | -------------: | -------------------: | --------------------: | --------------------: | ----------------: |
|         **1 000** |     0.00105775 |           0.00314454 |           0.000000167 |            0.00219242 |           4.37981 |
|        **10 000** |     0.00904271 |           0.00787392 |           0.000000166 |            0.00575467 |           5.23590 |
|       **100 000** |     0.03853630 |           0.07850100 |           0.000000125 |            0.05552650 |           5.88248 |
|     **1 000 000** |     0.38032100 |           0.76175200 |           0.000000166 |            0.51995500 |          13.66490 |
|    **10 000 000** |     4.82062000 |           8.46322000 |           0.000000166 |            6.29449000 |         101.23900 |


1. Pridėjau failų generavimo kodą;
2. Suskaidžiau programą į atskirus failus.
3. Pridėjau laiko matavimą bendroje programoje
4. pataisiau pagrindinę programą, pridėjau laiko matavimą, pridėjau galimybę pasirinkti nuskaitomo failo dydį.
5. Pridėjau testavimo rezulatatų išvedimą.
