# C++
***(Module 01)***

* ## Index
  1. **[Memory allocation](#memory-allocation)**
     * **[Stack vs heap memory](#stack-vs-heap-memory)**
  2. **[Pointers to members](#pointers-to-members)**
  3. **[Reference](#reference)**
  4. **[Switch statement](#switch-statement)**

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

## Switch statement