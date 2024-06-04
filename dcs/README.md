# C++
***(Module 01)***

## Index
01. **[Memory allocation](#memory-allocation)**
	* **[Stack vs heap memory](#stack-vs-heap-memory)**
02. **[Pointers to members](#pointers-to-members)**
03. **[Reference](#reference)**
04. **[Lifetime](#lifetime)**
05. **[Scope](#scope)**
06. **[Constant class instance in another class](#constant-class-instance-in-another-class)**
07. **[Destructor called without a constructor](#destructor-called-without-a-constructor)**
08. **[Streams](#streams)**
09. **[Data transfer modes](#data-transfer-modes)**
10. **[Text mode operations](#text-mode-operations)**
11. **[Advantages of using streams](#advantages-of-using-streams)**
12. **[File streams](#file-streams)**
13. **[Creating file objects](#creating-file-objects)**
14. **[Switch statement](#switch-statement)**

## Memory allocation
- `malloc()` um objeto não funciona em C++ porque não chama o construtor do objeto. Da mesma forma, se você fizer `free()` em um objeto, ele também não chamará o destruidor.
- `new()` e `delete()` usa `malloc()` e `free()` na realidade, mas também chamam o construtor e o destruidor de maneira apropriada.
- `new()` não aceita parâmetros. Portanto, é necessário pensar em maneiras de inicializar valores.

***Exemplo 1***
```cpp
// Inicializar uma variável na stack e na heap
#include <string>
#include <iostream>

class Student
{
	private:
		std::string _login;

	public:
		Student(std::string login) :_login(login)
		{
			std::cout << "Student " << this->_login << " is born" << std::endl;
		}

		~Student()
		{
			std::cout << "Student " << this->_login << " died" << std::endl;
		}
};

int main()
{
	Student		bob = Student("bfubar"); // inicializar na stack
	Student*	jim = new Student("jfubar"); // inicializar na heap

	// Do some stuff here

	delete jim; // jim is destroyed

	return (0); // bob is destroyed
}
```

***Output***
```bash
Student bfubar is born
Student jfubar is born
Student jfubar died
Student bfubar died
```

***Exemplo 2***
```cpp
// Inicializar uma array de classes na heap
#include <string>
#include <iostream>

class Student
{
	private:
		std::string _login;

	public:
		Student() :_login("ldefault")
		{
			std::cout << "Student " << this->_login << " is born" << std::endl;
		}

		~Student()
		{
			std::cout << "Student " << this->_login << " died" << std::endl;
		}
};

int main()
{
	Student*	students = new Student[5]; // new() does not take parameters

	// Do some stuff here

	delete [] students;

	return (0);
}
```

***Output***
```bash
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault is born
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
Student ldefault died
```
[↑ Index ↑](#index)

### Stack vs heap memory
***Ambas as memórias estão localizadas na RAM. A forma como a memória será atribuída é diferente***

- Stack
  - Possui tamanho predefinido (cerca de 2 GB)
  - Quando queremos usar a memória da **stack**, o ponteiro da stack se move e aloca o tamanho da memória que desejamos e retorna o ponteiro da stack. Portanto, os valores que atribuímos na stack estarão próximos uns dos outros e serão atribuídos ao contrário. Uma alocação de memória de pilha é uma instrução de CPU e muito rápida
  - Assim que o escopo no qual você alocou a memória da stack terminar, toda a memória alocada na stack será recuperada
  - O Stack overflow (estouro de pilha) ocorre quando toda a memória da stack foi alocada, nesse caso, outras alocações começam a transbordar para outras seções da memória
  - Se você puder alocar na stack, escolha stack

- Heap
  - Tem um tamanho predefinido, mas pode crescer
  - Use `new()` palavra-chave para alocar no heap
  - **Solicitações de memória sequencial podem não resultar na alocação de endereços de memória sequencial**
  - A memória alocada no heap precisa ser liberada manualmente
  - A memória alocada dinamicamente deve ser acessada por meio de um ponteiro. **Desreferenciar um ponteiro é mais lento do que acessar uma variável diretamente**

***Exemplo 1***
```cpp
class Vector
{
	float x, y, z;
}

int main()
{
	//allocate on the stack
	int value = 5;
	int array[5];
	Vector vector;

	// allocate on the heap
	int* hvalue = new int;
	hvalue = 5;
	int* harray = new int[5];
	Vector* hvector = new Vector();

	// need to delete() all the new() allocation
	delete hvalue;
	delete[] harray;
	delete hvector;
}
```
[↑ Index ↑](#index)

## Pointers to members
- Ponteiros
  - Os ponteiros são extremamente importantes para gerenciar e manipular a memória
  - Um ponteiro é um número inteiro que armazena um endereço de memória. É o endereço de onde está essa memória específica.
  - Os tipos desse ponteiro não importam. Indica apenas o tipo de dados que presumivelmente estão armazenados. É algo que escrevemos para tornar nossas vidas mais fáceis sintaticamente. O tipo não altera o que é um ponteiro
  - Apontar para um endereço de memória inválido (como 0) é perfeitamente adequado para ponteiro
  - Ao colocar `&` antes de uma variável, estamos perguntando o endereço dessa variável
  - Desreferenciar (*ptr) significa acessar os dados. Dessa forma, você pode gravar ou ler os dados
  - Os próprios ponteiros também são variáveis ​​​​e armazenados na memória
- Pointers to members em C++ 
  - permitem apontar para membros específicos de uma classe, sejam eles atributos ou métodos. 
  - Eles são úteis para acessar membros dinamicamente, permitindo uma maior flexibilidade e reusabilidade do código. 
  - Usando a sintaxe adequada, você pode declarar, inicializar e usar esses ponteiros para acessar membros de objetos ou invocar métodos.

***Exemplo 1***
```cpp
// pointers to data members e pointers to member functions
#include <iostream>

class MyClass {
public:
    int data;

    void setData(int value) {
        data = value;
    }

    void display() const {
        std::cout << "Data: " << data << std::endl;
    }
};

int main() {
    MyClass obj;

    // Ponteiro para membro de dados
    int MyClass::*ptrToData = &MyClass::data;

    // Ponteiro para método
    void (MyClass::*ptrToSetData)(int) = &MyClass::setData;
    void (MyClass::*ptrToDisplay)() const = &MyClass::display;

    // Usando os ponteiros
    (obj.*ptrToSetData)(42);  // Chama obj.setData(42)
    (obj.*ptrToDisplay)();    // Chama obj.display() -> Output: Data: 42
	std::cout << obj.*ptrToData << std::endl; // Output: 42
    return 0;
}
```
[↑ Index ↑](#index)

## Reference
***As referências são apelidos para variáveis ​​existentes. É um ponteiro que é `constante` e sempre `desreferenciado` e nunca `anulado`***

- Referência
  - Uma maneira de fazermos referência a uma variável existente. Mas o ponteiro pode apontar para um endereço inexistente
  - Referências não são variáveis ​​novas. eles realmente não ocupam memória ou têm armazenamento
  - `int& ref = a`; `&` faz parte do tipo. Na verdade, criamos um alias
  - Ao passar um valor para uma função, você está passando uma cópia do valor. Para que a função de destino altere o valor, você precisa passar o endereço de memória dessa variável (usando uma referência ou um ponteiro)
  - `*value++;` Devido à ordem de operação, ele será incrementado primeiro e depois desreferenciado. O correto é desreferenciar primeiro e incrementar depois `(*value)++`
  - Se puder, use referência e isso fará com que o código-fonte pareça mais limpo
  - Depois de definir uma referência, você não poderá alterar o que é uma referência

- Referências vs. ponteiro
  - Você não pode alterar para onde a referência está apontando. Sempre apontará para a mesma variável
  - Você não pode criar uma referência e deixá-la apontar para nada (referência não inicializada). Por ser constante, você não pode apontar para outra coisa posteriormente. Mas uma referência não pode apontar para nada
  - Vantagem: quando você tem uma referência, tem certeza de que ela está apontando para algo
  - A referência é como um ponteiro desreferenciado. Então você não precisa adicionar nenhum símbolo para acessá-lo
- As referências são complementares aos ponteiros, mas não os substituem. No entanto, você não pode ter uma referência e não inicializá-la com alguma coisa. Em comparação, usando um ponteiro, você pode apontá-lo para algo que não existe no início e alterar o que ele aponta mais tarde
- Ponteiros e referências são essencialmente a mesma coisa em relação ao comportamento do computador com eles. Os ponteiros são mais flexíveis que as referências. Se algo sempre existir e nunca mudar, use referências. Mas se nem sempre existir e puder mudar, use um ponteiro.

***Exemplo 1***
```cpp
#include <iostream>

int	main()
{
	int		numberOfBalls = 42;

	int*	ballsPtr = &numberOfBalls;
	int&	ballsRef = numberOfBalls;
	// the reference will be pointing to the variable
	// from this point on, you can't change what your reference is pointing to

	std::cout << numberOfBalls << " " << *ballsPtr << " " << ballsRef << std::endl;

	*ballsPtr = 21;
	std::cout << numberOfBalls << std::endl;
	ballsRef = 84;
	std::cout << numberOfBalls << std::endl;

	return (0);
}
```
***Output***
```bash
42 42 42
21
84
```

***Exemplo 2***
```cpp
// Passing parameters by reference
#include <iostream>
#include <string>

void byPtr(std::string* str)
{
	*str += " and ponies";
}

void byConstPtr(std::string const * str)
{
	std::cout << *str << std::endl;
}

void byRef(std::string& str)
{
	str += " and ponies";
}

void byConstRef(std::string const & str)
{
	std::cout << str << std::endl;
}

int main()
{
	std::string str = "i like butterflies";

	std::cout << str << std::endl;
	byPtr(&str);
	byConstPtr(&str);

	str = "i like otters";

	std::cout << str << std::endl;
	byRef(str);
	byConstRef(str);

	return (0);
}
```
***Output***
```bash
i like butterflies
i like butterflies and ponies
i like otters
i like otters and ponies
```

***Exemplo 3***
```cpp
// const reference and pointer
#include <iostream>
#include <string>

class Student
{
	private:
		std::string _login;

	public:
		Student(std::string const & login) : _login(login)
		{
		}

		std::string&	getLoginRef()
		{
			return this->_login;
		}

		std::string const & getLoginRefConst() const
		{
			return this->_login;
		}

		std::string*	getLoginPtr()
		{
			return &(this->_login);
		}

		std::string const * getLoginPtrConst() const
		{
			return &(this->_login);
		}
};

int main()
{
	Student 	bob = Student("bfubar");
	Student const jim = Student("jfubar");

	// use a const function on a non-const variable is not a problem
	std::cout << bob.getLoginRefConst() << " " << jim.getLoginRefConst() << std::endl;
	std::cout << *(bob.getLoginPtrConst()) << " " << *(jim.getLoginPtrConst()) << std::endl;

	bob.getLoginRef() = "bobfubar";
	std::cout << bob.getLoginRefConst() << std::endl;

	*(bob.getLoginPtr()) = "bobbyfubar";
	std::cout << bob.getLoginRefConst() << std::endl;

	return (0);
}
```
***Output***
```bash
bfubar jfubar
bfubar jfubar
bobfubar
bobbyfubar
```
[↑ Index ↑](#index)

## Lifetime
***A vida útil de uma variável ou objeto é o período de tempo em que a variável/objeto possui memória válida . Também é chamado `allocation method` e `storage duration`.***
- **Estático:** uma variável estática é armazenada no segmento de dados de um programa `object file`. Seu tempo de vida é toda a duração da execução do programa.
- **Automático:** uma variável automática tem um tempo de vida que começa quando a execução do programa entra na função ou bloco de instruções ou composto e termina quando a execução sai do bloco. Variáveis ​​automáticas são armazenadas em uma "pilha de chamadas de função".
- **Dinâmico:** O tempo de vida de um objeto dinâmico começa quando a memória é alocada para o objeto (por exemplo, após chamar `malloc()` ou `new()`) e termina quando a memória é desalocada (por exemplo, após chamar `free()` ou `delete()`). Objetos dinâmicos são armazenados na "heap".

[↑ Index ↑](#index)

## Scope
***C/C++ usa escopo léxico. O escopo de uma declaração é a parte do programa para a qual a declaração está em vigor.***
- **Escopo local:** visível nas funções ou no bloco de instruções desde o ponto da declaração até o final do bloco
- **scopo da class:** visto pelos membros da classe
- **Escopo do namespace:** visível no bloco de namespace
- **Escopo do arquivo:** visível no arquivo de texto atual
- **Escopo global:** visível em todos os lugares, a menos que esteja "oculto"

[↑ Index ↑](#index)

## Constant class instance in another class
***Em uma classe, você pode ter um atributo de classe de outra classe. Defini-lo como `constant` significa que você não pode modificá-lo após a inicialização.***

Para garantir que a instância tenha o mesmo tempo de vida da classe:
- Se você declarar a instância no heap, deverá excluí-la no momento apropriado
- Se você declarar a instância na stack, ela morrerá após sair do escopo

### Exemplo de Atributo de Classe Constante em C++

Considere o seguinte cenário:

Temos duas classes: `Pessoa` e `Endereco`. A classe `Pessoa` possui um atributo `endereco` do tipo `Endereco`. 

**Classe Pessoa:**

```c++
class Pessoa {
public:
  Pessoa(const Endereco& endereco);
  // Outros métodos...

private:
  const Endereco endereco; // Atributo de classe constante
};
```

**Classe Endereco:**

```c++
class Endereco {
public:
  Endereco(const std::string& rua, const std::string& cidade, const std::string& estado, const unsigned int& cep);
  // Outros métodos...

private:
  std::string rua;
  std::string cidade;
  std::string estado;
  unsigned int cep;
};
```

Na classe `Pessoa`, o atributo `endereco` é declarado como `const`. Isso significa que, após a inicialização do objeto `Pessoa`, o valor do atributo `endereco` não pode ser alterado. 

**Exemplo de uso:**

```c++
Endereco enderecoResidencial("Rua Principal", "Lisboa", "Portugal", 12345);
Pessoa pessoa(enderecoResidencial);

// O código a seguir gerará um erro de compilação, pois o atributo 'endereco' é constante:
// pessoa.endereco.rua = "Rua Nova";
```

**Explicação:**

* O modificador `const` após a declaração do tipo do atributo indica que o valor do atributo não pode ser alterado após a inicialização.
* Isso garante a imutabilidade do atributo, tornando o código mais robusto e confiável.
* Atributos de classe constantes são úteis em situações onde o estado do objeto não deve ser modificado após sua criação.

**Benefícios:**

* **Maior segurança:** Impede a modificação acidental do estado do objeto.
* **Melhor legibilidade:** O código fica mais claro e fácil de entender.
* **Manutenção aprimorada:** Mudanças no código são menos propensas a causar efeitos colaterais indesejados.

**Observações:**

* É possível ter métodos de classe que modificam o estado de um objeto, mesmo que o objeto tenha atributos de classe constantes. Isso é feito usando a palavra-chave `mutable` antes da declaração do método.
* Atributos de classe constantes também podem ser inicializados em uma lista de inicialização.

[↑ Index ↑](#index)

## Destructor called without a constructor
- Passar uma instância de uma classe por valor (não por ponteiro ou referência) invoca o construtor de cópia. O compilador implementa o construtor de cópia por padrão se a definição de classe não fornecer explicitamente um
- O construtor de cópia gerado pelo compilador não chamará nenhum dos outros construtores que você implementou. Mas o destruidor será invocado para limpar a cópia quando terminar.
- Quando você passa uma instância para outra função, quando a função é executada, ela é adicionada à stack para ser processada. Uma cópia da instância é enviada para a stack, não a instância real. Portanto, o sistema utilizará um construtor de cópia para criar uma cópia e quando a cópia local estiver fora do escopo, o destruidor será chamado. Porém, neste caso, o construtor padrão não é chamado.
- **Para realmente alterar a instância original, você precisa passar a instância com um ponteiro ou uma referência**. Portanto, a função pode realmente acessar o local da instância original e fazer alterações nessa instância/membro de dados. Se tal caso existir, uma decisão precisa ser tomada entre uma referência e um ponteiro

[↑ Index ↑](#index)

## Streams
- Um `stream` (fluxos) é uma representação abstrata de um dispositivo de entrada ou de saída que é uma fonte ou destino sequencial de dados em seu programa. É representado por um tipo de classe.
- Você pode visualizar um stream como uma sequência de bytes fluindo entre um dispositivo externo e a memória principal do seu computador. Você pode gravar dados em um `output stream` e ler dados de um `input stream`; alguns streams fornecem a capacidade de entrada e saída.
- Em resumo, todas as entradas e saídas são uma sequência de bytes lidos ou gravados em algum dispositivo externo.
Ao ler dados de um dispositivo externo, cabe a você interpretá-los corretamente. Você precisa conhecer a estrutura e o tipo de dados com antecedência, e lê-los e interpretá-los adequadamente.

**Tipos Comuns de Streams em C++:**
- **cin:** Stream de entrada padrão, utilizado para ler dados do teclado.exclamation
- **cout:** Stream de saída padrão, utilizado para imprimir dados na tela.expand_more
- **cerr:** Stream de erro padrão, utilizado para imprimir mensagens de erro.exclamation
- **fstream:** Classe genérica para criar e manipular streams de arquivos.expand_more
- **ostringstream:** Stream de saída para strings, permitindo que você armazene dados em uma string como se estivesse escrevendo em um arquivo.
- **istringstream:** Stream de entrada para strings, permitindo que você processe dados em uma string como se estivesse lendo de um arquivo ou do teclado.

[↑ Index ↑](#index)

## Data transfer modes
- Existem dois modos para transferir dados de e para um fluxo (stream): modo texto e modo binário.
- No modo `text`, os dados são interpretados como uma sequência de caracteres que geralmente é organizada como uma ou mais linhas terminadas pelo caractere de nova linha `'\n'`. Diferentes sistemas interpretam o caractere de nova linha de maneira diferente. No sistema Unix, permanece um único caractere
- No modo `binary`, não há transformação de dados. Os bytes originais são transferidos entre a memória e o fluxo sem conversão.

[↑ Index ↑](#index)

## Text mode operations
- Você pode ler e gravar vários tipos de dados usando os operadores de extração e inserção `>>` e `<<`. Estas são operações de I/O formatadas que ocorrem em modo texto.

[↑ Index ↑](#index)

## Advantages of using streams
- A principal razão para usar fluxos (streams) para operações de I/O é tornar o código das operações independente do dispositivo físico.
  - Você não precisa se preocupar com a mecânica detalhada de cada dispositivo. Eles são todos atendidos nos bastidores
  - Um programa funcionará com uma variedade de dispositivos físicos diferentes sem a necessidade de alterações no código-fonte.
- A realidade física de um fluxo de saída pode ser qualquer dispositivo para o qual uma sequência de bytes possa ser transferida. A I/O do fluxo de arquivos normalmente será para um arquivo em um disco ou em um dispositivo de estado sólido.

- A biblioteca padrão define três objetos de fluxo de saída padrão
  - `std::cout:` fluxo de saída padrão
  - `std::cerr:` fluxo de erro padrão sem buffer (os dados são gravados imediatamente no dispositivo de saída)
  - `std::clog:` fluxo de erro padrão em buffer (os dados só serão gravados quando o buffer estiver cheio)
- Em princípio, um fluxo de entrada pode ser qualquer fonte serial de dados, mas normalmente é um arquivo de disco ou o teclado.

[↑ Index ↑](#index)

## File streams
- Streams que interagem com arquivos. Existem três tipos de objetos de fluxo para trabalhar com arquivos: `ifstream`, `ofstream` e `fstream`.
  - Essas classes têm `istream`, `ostream` e `iostream` como classes base, respectivamente.
  - Um objeto `ifstream` representa um fluxo de entrada de arquivo, então você só pode lê-lo.
  - Um objeto `ofstream` representa um fluxo de saída de arquivo que você só pode gravar nele.
  - Um `fstream` é um fluxo de arquivos que você pode ler ou escrever.
- Você pode associar um objeto de fluxo de arquivos a um arquivo físico ao criá-lo. Você também pode criar um objeto de fluxo de arquivo que não esteja associado a um arquivo e, em seguida, chamar um membro de função para estabelecer a conexão com um arquivo específico.
- Para ler ou gravar um arquivo, você deve “abrir” o arquivo; isso anexa o arquivo ao seu programa por meio do sistema operacional com um conjunto de permissões que determinam o que você pode fazer com ele. Se você criar um objeto de fluxo de arquivos com uma associação inicial a um arquivo, o arquivo será aberto e estará disponível para uso imediatamente.
- Um fluxo de arquivos possui algumas propriedades importantes. Possui um `length`, que corresponde ao número de caracteres do stream; possui um `beginning`, que é a posição de índice do primeiro caractere no fluxo; e tem um `end`, que é a posição do índice um após o último caractere no fluxo. Ele também possui um `current position`, que é a posição de índice do caractere no fluxo onde a próxima operação de leitura ou gravação será iniciada. O `first character` fluxo de um arquivo está na posição de índice 0. Essas propriedades fornecem uma maneira de mover-se em um arquivo para ler as partes específicas de seu interesse ou substituir áreas selecionadas do arquivo.

***Exemplo 1***
```cpp
#include <iostream>
#include <fstream>

int main()
{
	//ifstream: input file stream
	std::ifstream	ifs("numbers");
	unsigned int	dst;
	unsigned int	dst2;
	ifs >> dst >> dst2;

	std::cout << dst << " " << dst2 << std::endl;
	ifs.close();

	//-------------------------
	//ofstream: output file stream
	std::ofstream	ofs("test.out");
	ofs << "i like ponies a whole damn lot" << std::endl;
	ofs.close();
	return (0);
}
```
***Output***
```bash
# these come from the numbers from the numbers file
8 5
$ cat test.out
i like ponies a whole damn lot
```

***Exemplo 2***
```cpp
#include <iostream>
#include <fstream>

int main() {
  // Abre o arquivo "data.txt" para escrita
  std::ofstream arquivo("data.txt");

  // Verifica se a abertura foi bem sucedida
  if (arquivo.is_open()) {
    // Escreve dados no arquivo
    arquivo << "Nome: João Silva\nIdade: 30\nCidade: Lisboa";

    // Fecha o arquivo
    arquivo.close();
  } else {
    std::cerr << "Erro ao abrir o arquivo!" << std::endl;
  }

  // Abre o arquivo "data.txt" para leitura
  std::ifstream arquivoLeitura("data.txt");

  // Verifica se a abertura foi bem sucedida
  if (arquivoLeitura.is_open()) {
    std::string linha;

    // Lê cada linha do arquivo até o fim
    while (std::getline(arquivoLeitura, linha)) {
      // Imprime a linha na tela
      std::cout << linha << std::endl;
    }

    // Fecha o arquivo
    arquivoLeitura.close();
  } else {
    std::cerr << "Erro ao abrir o arquivo para leitura!" << std::endl;
  }

  return 0;
}
```

[↑ Index ↑](#index)

## Creating file objects
- Ao contrário dos objetos cin e cout padrão, os objetos de arquivo de entrada e saída devem ser criados pelo programador.

[↑ Index ↑](#index)

## Switch statement

O `switch statement` em C++ é uma instrução de fluxo de controle que permite executar diferentes blocos de código com base no valor de uma expressão. É uma ferramenta poderosa para organizar e simplificar código que depende de condições específicas.

**Funcionamento:**

1. **Avaliação da expressão:** O valor da expressão fornecida no `switch statement` é avaliado.
2. **Comparação com valores dos casos:** O valor avaliado é comparado com os valores de cada caso ("case") dentro do `switch statement`.
3. **Execução do bloco de código correspondente:** Se o valor da expressão coincidir com o valor de um caso, o bloco de código associado a esse caso será executado.
4. **Instrução `default` (opcional):** Se nenhum valor de caso coincidir com o valor da expressão, a instrução `default` (se presente) será executada.

**Estrutura:**

```c++
switch (expressao) {
  case valor1:
    // Código a ser executado se a expressão for igual a valor1
    break;
  case valor2:
    // Código a ser executado se a expressão for igual a valor2
    break;
  // ...
  default:
    // Código a ser executado se nenhum valor de caso coincidir
}
```

**Exemplo:**

```c++
#include <iostream>

int main() {
  int dia = 3;

  switch (dia) {
    case 1:
      std::cout << "Segunda-feira" << std::endl;
      break;
    case 2:
      std::cout << "Terça-feira" << std::endl;
      break;
    case 3:
      std::cout << "Quarta-feira" << std::endl;
      break;
    case 4:
      std::cout << "Quinta-feira" << std::endl;
      break;
    case 5:
      std::cout << "Sexta-feira" << std::endl;
      break;
    case 6:
      std::cout << "Sábado" << std::endl;
      break;
    case 7:
      std::cout << "Domingo" << std::endl;
      break;
    default:
      std::cout << "Dia inválido!" << std::endl;
  }

  return 0;
}
```

**Vantagens do `switch statement`:**

* **Organização:** Permite estruturar o código de forma clara e concisa, facilitando a leitura e a manutenção.
* **Eficiência:** Evita o uso de instruções `if-else` aninhadas, otimizando o desempenho do código.
* **Legibilidade:** Torna o código mais intuitivo e compreensível, especialmente quando se trata de múltiplas condições.

**Observações:**

* O valor da expressão deve ser de um tipo integral ou conversível para um tipo integral.
* A instrução `break` é usada para sair do `switch statement` após a execução do bloco de código correspondente.
* A instrução `default` é opcional, mas recomendada para tratar de casos em que o valor da expressão não se encaixa em nenhum caso.
* O `switch statement` pode ser usado em conjunto com outras instruções de fluxo de controle, como `if` e `for`.

[↑ Index ↑](#index)
