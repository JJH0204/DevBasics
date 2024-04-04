# DevBasics.md

## 학습 목표
- 기본 프로그래밍 및 컴퓨터 과학 개념 학습을 목표로 합니다.

## 학습 주제
- C/C++언어 고급: 포인터 메모리 관리, 파일 입출력, 구조체와 공용체를 포함한 고급 문법 학습
- 자료구조 기초/심화: 리스트, 스택, 큐, 트리, 그래프 등 자료구조를 실제 구현 및 문제에 적용하는 방법 학습
- 알고리즘 기초: 정렬, 검색, 기본적인 알고리즘 문제 해결 방법 학습
- 객체지향 프로그래밍 기초: 객체지향 프로그래밍의 원리를 이해하기 위한 기초를 학습


## 필수 조건
- 각 개념을 실습하며, 작은 프로젝트 또는 알고리즘을 해결하며 이론과 실제를 연결합니다.

## 준비
- [ **VSCode Setup** ](markdown/VSCode_Setup.md)
- [ **Using Cmake** ](markdown/CMake.md)

## 학습 과정

<details>
<summary>C_Language</summary>
<div markdown="1">   

| 주제                            | 성취도 | .md                                                                                          | 소스코드                                                                                                                      |
| ------------------------------- | :----: | :------------------------------------------------------------------------------------------- | :---------------------------------------------------------------------------------------------------------------------------- |
| Hello world                     |   📌    | -                                                                                            | [main.c](source/C_language/Hello.c)                                                                                           |
| Variables and Types             |   📌    | -                                                                                            | [main.c](source/C_language/VnT.c)                                                                                             |
| Arrays                          |   📌    | -                                                                                            | [main.c](source/C_language/Arrays.c)                                                                                          |
| Multidimensional Arrays         |   📌    | -                                                                                            | [main.c](source/C_language/MultiArrays.c)                                                                                     |
| Conditions                      |   📌    | -                                                                                            | [main.c](source/C_language)                                                                                                   |
| Strings                         |   📌    | -                                                                                            | [main.c](source/C_language/Strings.c)                                                                                         |
| loops                           |   📌    | -                                                                                            | [main.c](source/C_language/loops.c)                                                                                           |
| Functions                       |   📌    | -                                                                                            | [main.c](source/C_language/functions.c)                                                                                       |
| Static                          |   📌    | -                                                                                            | [main.c](source/C_language/static.c)                                                                                          |
| Pointers                        |   📌    | -                                                                                            | [main.c](source/C_language/pointers.c)                                                                                        |
| Structures                      |   📌    | -                                                                                            | [main.c](source/C_language/structures.c)                                                                                      |
| Function arguments by reference |   📌    | -                                                                                            | [main.c](source/C_language/FunArgByRef.c)                                                                                     |
| Dynamic allocation              |   📌    | -                                                                                            | [main.c](source/C_language/DynamicAllocation.c)                                                                               |
| Arrays and Pointers             |   📌    | -                                                                                            | [main.c](source/C_language/ArrayNPointer.c)                                                                                   |
| Recursion                       |   📌    | [Kor](markdown/DataStructure/recursion.md)                                                   | [main.c](source/C_language/recursion.c)                                                                                       |
| Linked lists                    |   📌    | [Eng](markdown/DataStructure/LinkedLists.md) [Kor](markdown/DataStructure/LinkedLists_kr.md) | [main.c](source/C_language/LinkedLists.c) [ExCode.c](source/C_language/ExLinkedLists.c)                                       |
| Binary trees                    |   📌    | [Kor](markdown/DataStructure/Tree.md)                                                        | [main.c](source/C_language/CompleteBinaryTree.c) [Excode.c](source/C_language/ExBinarytrees.c)                                |
| Unions                          |   📌    | [Eng](markdown/C/Unions.md) [Kor](markdown/C/Unions_kr.md)                                   | [main.c](source/C_language/Unions.c) [Excode.c](source/C_language/ExUnions.c) [testcode.c](source/C_language/ExUnions_test.c) |
| Pointer Arithmetics             |   📌    | [Eng](markdown/C/Pointer%20Arithmetics.md) [Kor](markdown/C/Pointer%20Arithmetics_kr.md)     | [main.c](source/C_language/PointerArithmetics.c) [Excode.c](source/C_language/ExPointerArithmetics.c)                         |
| Function Pointers               |   📌    | [Eng](markdown/C/Function%20Pointers.md) [Kor](markdown/C/Function%20Pointers_kr.md)         | [main.c](source/C_language/FunctionPointers.c) [Excode.c](source/C_language/ExFunctionPointers.c)                             |
| Bitmasks                        |   📌    | [Eng](markdown/C/Bitmasks.md) [Kor](markdown/C/Bitmasks_kr.md)                               | [main.c](source/C_language/Bitmasks.c) [Excode.c](source/C_language/ExBitmasks.c)                                             |

</div>
</details>

<details open>
<summary>Data Structure and Algorithms</summary>
<div markdown="1">   

| 주제                              | check | .md                                                                                            | .main                                                                                                                                                   | .include                                                                                                                                                                                                                                                 |
| :-------------------------------- | :---: | :--------------------------------------------------------------------------------------------- | :------------------------------------------------------------------------------------------------------------------------------------------------------ | :------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| data structures and algorithms    |       | [Kor](markdown/Data%20Structure%20N%20Algorithms.md)                                           |
| Array list                        |   📌   | [Kor](markdown/DataStructure/ArrayList.md)                                                     | [main.c](source/DSNA/Linear/mainArrayList.c)                                                                                                            |
| Linked list                       |   📌   | [Kor](markdown/DataStructure/LinkedLists_kr.md) , [Eng](markdown/DataStructure/LinkedLists.md) | [main.c](source/DSNA/Linear/mainLinkedList.c)                                                                                                           |
| Extension of linked list          |   📌   | [Kor](markdown/DataStructure/LinkedList_Add.md)                                                | [mainDoubleLinkedList.c](source/DSNA/Linear/mainDoubleLinkedList.c) , [mainCircularLinkedList.c](source/DSNA/Linear/mainCircularLinkedList.c)           |
| Uses of Linked Lists: Polynomials |   📌   | [Kor](markdown/DataStructure/Polynomial.md)                                                    | [main.c](source/DSNA/Linear/mainPolynomial.c)                                                                                                           |
| Stack                             |   📌   | [Kor](markdown/DataStructure/stack.md)                                                         | [mainArrayStack.c](source/DSNA/Linear/mainArrayStack.c) , [mainStack.c](source/DSNA/Linear/mainStack.c)                                                 |
| Using Stack                       |   📌   |                                                                                                | [mainReverseString.c](source/DSNA/Linear/mainReverseString.c) , [mainCheckBracketMatch.c](source/DSNA/Linear/mainCheckBracketMatch.c)                   | [includeStack.c](source/DSNA/Linear/includeStack.c) , [includeStack.h](include/includeStack.h)                                                                                                                                                           |
| fostfix                           |   📌   |                                                                                                | [mainPostfix.c](source/DSNA/Linear/mainPostfix.c)                                                                                                       | [includeNotationStack.c](source/DSNA/Linear/includeNotationStack.c) , [includePostfix.c](source/DSNA/Linear/includePostfix.c) , [includeNotationStack.h](include/includeNotationStack.h) , [includePostfix.h](include/includePostfix.h)                  |
| Queue                             |   📌   | [Kor](markdown/DataStructure/queue.md)                                                         | [mainArrayQueue.c](source/DSNA/Linear/mainArrayQueue.c) , [mainQueue.c](source/DSNA/Linear/mainQueue.c) , [mainDeque.c](source/DSNA/Linear/mainDeque.c) |
| Recursion                         |       | [Kor](markdown/DataStructure/recursion.md)                                                     | [mainFibonacci.c](source/DSNA/Linear/mainFibonacci.c) , [mainHanoi.c](source/DSNA/Linear/mainHanoi.c)                                                   |
| Tree                              |   📌   | [Kor](markdown/DataStructure/Tree.md)                                                          | [mainBinaryTree.c](source/DSNA/non-Linear/mainBinaryTree.c)                                                                                             | [includeBinTree.c](source/DSNA/non-Linear/includeBinTree.c), [includeBinTree.h](include/includeBinTree.h), [includeGenericStructure.c](source/DSNA/non-Linear/includeGenericStructure.c), [includeGenericStructure.h](include/includeGenericStructure.h) |
| Heap                              |   📌   | [Kor](markdown/DataStructure/Heap.md)                                                          | [mainHeap.c](source/DSNA/non-Linear/mainHeap.c)                                                                                                         | [includeHeap.c](source/DSNA/non-Linear/includeHeap.c), [includeHeap.h](include/includeHeap.h)                                                                                                                                                            |
| Priority Queue                    |   📌   | [Kor](markdown/DataStructure/PriorityQueue.md)                                                 | [mainPriorityQueue.c](source/DSNA/non-Linear/mainPriorityQueue.c)                                                                                       | [includeHeap.c](source/DSNA/non-Linear/includeHeap.c), [includeHeap.h](include/includeHeap.h)                                                                                                                                                            |
| Graph                            |       | [Graph.md](markdown/DataStructure/Graph.md), [makeGraph.md](markdown/DataStructure/MakeGraph.md)|[mainGraph.c](source/DSNA/non-Linear/mainGraph.c)|[includeArrayGraph.c](source/DSNA/non-Linear/includeArrayGraph.c), [includeArrayGraph.h](include/includeArrayGraph.h), [includeLinkedGraph.c](source/DSNA/non-Linear/includeLinkedGraph.c), [includeLinkedGraph.h](include/includeLinkedGraph.h)
| 검색                              |       |

</div>
</details>

<details>
<summary>객체지향 (with. C++)</summary>
<div markdown="1">   

| 주제 | check | .md  | .main | .include |
| ---- | :---- | :--- | :---- | :------- |
|      |

</div>
</details>

## 참조
* [GPT가 추천하는 프로그래머 준비과정](markdown/Curriculum_Advised_by_Chat_GPT.md)
* [Learn-c.org](https://www.learn-c.org/)
* [자료구조 입문](https://www.yes24.com/Product/Goods/28194882)