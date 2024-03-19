// Deque.c
/* TODO: Implementation of a deque that extends the queue
deque: double-ended queue
- 양쪽 끝에서 데이터의 삽입과 반환이 모두 가능한 자료형
*/
/*
|            name |    input    |  output  | desc                         |
| --------------: | :---------: | :------: | :--------------------------- |
|   createDeque() |             |  deque   | 빈 덱 생성                   |
|   deleteDeque() |    deque    | 성공여부 | 덱 삭제(메모리 해제)         |
|       isEmpty() |    deque    |   bool   | 빈 덱인지 반환               |
| enqueue_Front() | deque, data | 성공여부 | 프런트에 새로운 데이터 추가  |
|  enqueue_Rear() | deque, data | 성공여부 | 리어에 새로운 데이터 추가    |
| dequeue_Front() |    deque    |   data   | 프런드에 데이터 반환 후 삭제 |
|  dequeue_Rear() |    deque    |   data   | 리어에 데이터 반환 후 삭제   |
|    peek_Front() |    deque    |   data   | 프런트에 데이터 반환         |
|     peek_Rear() |    deque    |   data   | 리어에 데이터 반환           |
|  displayDeque() |    deque    |          | 덱 저장된 데이터 전부 출력   |
*/