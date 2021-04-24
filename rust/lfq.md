# Lock Free Queue 

I have implemented a simple lock-free queue inspired by http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.53.8674&rep=rep1&type=pdf with Rust lanuage 

The queue features 

1. Linked list structure with Rust enum and Arc traits 
2. CAS to prevent the context switching when the thread wanna offer a new node and poll a current head 
3. solve the ABA problem with the version machinesm 

but in this implementation no method to let the queue blocks on an empty queue ?


safe properties 

non-block once the oprtation submited within the finite steps the operation shoul be executed 
wait-free every process will complete the operation within the finite steps 

```python
poll:
  for {
    let current = head 
    if current == nil return nil;
    if CAS(head, current, current.next) # but at this point the heade pointer maybe nil and the other routine currently to set the tail pointer to a new node, so how to fix it when the first time offer when the queue is empty .
      return current 
  }
  
```

## though the lock free is non-blocking but the lock free and concurrent datastructure should keep the linerizable properties

so the offer method should be that we have to implement the first change the current tail and linked then again and then we have to do the other tail chaneg operations 



