## Projeto de Programação 1
###### por [Natália Azevedo de Brito](https://github.com/bnatalha)

O programa gerado pelo makefile calcula estatísticas e resultados para multiplicações das matrizes presentes em `data/input` (multiplicando _Anxn.txt_ por _Bnxn.txt_), gravando as matrizes resultantes das multiplicações em `data/output` (_Cnxn.txt_). As estatísticas com relação ao tempo de execução __em centésimos__ das multiplicações feitas iterativamente seram salvas em `data/stats-ite.dat`, e em `data/stats-rec.dat` seram salvas as feitas recursivamente, que levará em consideração tempos gastos em 20 execuções de cada dimensão especificada como argumento quando o programa é chamado para ser executado pelo terminal.

Cada linha dos arquivos `.dat` possui (i) a _dimensão_ das matrizes utilizadas para efetuar a mutiplicação, (ii) _tempo mínimo_ de execução, (iii) _tempo máximo_, (iv) _média_ e (v) _desvio padão_, respectivamente.

---

### Compilando:

`$ make`

### Gerando Documentação:

Documentação (a ser completada) no formato _.html_ será gerada em `docs/`

`$ make doc`

### Executando:

__ATENÇÃO__ : utilize __apenas__ valores que são __potências de base 2__ como argumentos.

`$ bin/main 2 8 32`
###### onde '2' '16' e '4' são os valores das dimensões (ex.: 2x2, 16x16 e 4x4) das matrizes a serem utilizadas no teste.
