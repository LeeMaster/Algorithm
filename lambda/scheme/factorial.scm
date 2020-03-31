(define (factorial n)
  (lambda (n) 
    (if (= n 0) 1
      (* n factorial(- n 1)))))

(define (factorial_loop n)
  ; use the recurive to replace the tranditional loop like CXX 
  ; in scheme this expression will expend and replace with the parameter 
  (define (factorial_iter product count) 
    (if (> count n)
      product
      (factorial_iter (* count product) (+ 1 count))))

  (factorial_iter 1 1))