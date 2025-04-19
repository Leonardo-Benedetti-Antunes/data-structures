package main

// List overload interface

type List[T any] interface {
	Append(valor T)
}

// Nodes struct def

type SLLNode[T any] struct {
	value any
	next  *SLLNode[T]
}

type DLLNode[T any] struct {
	value any
	next  *DLLNode[T]
	prev  *DLLNode[T]
}

// Actual lists struct def

type SinglyLinkedList[T any] struct {
	Head *SLLNode[T]
}

type DoublyLinkedList[T any] struct {
	Head *DLLNode[T]
	Tail *DLLNode[T]
}

// Lists append funcs

func (l *SinglyLinkedList[T]) Append(valor T) {
	newNode := &SLLNode[T]{value: valor}
	if l.Head == nil {
		l.Head = newNode
		return
	}
	current := l.Head
	for current.next != nil {
		current = current.next
	}
	current.next = newNode
}

func (l *DoublyLinkedList[T]) Append(valor T) {
	newNode := &DLLNode[T]{value: valor}
	if l.Head == nil {
		l.Head = newNode
		l.Tail = newNode
		return
	}
	l.Tail.next = newNode
	newNode.prev = l.Tail
	l.Tail = newNode
}

// List constructor

func list[T any](modo int) List[T] {
	switch modo {
	case 1:
		return &SinglyLinkedList[T]{}
	case 2:
		return &DoublyLinkedList[T]{}
	default:
		panic("wrong usage")
	}
}
