(define exists?
    (lambda (pred lst)
      (cond
        ((null? lst) #f)
    ((not (not(pred (car lst)))) #t)
    (else (exists? pred (cdr lst))))))


  (display (exists? number? '(a b c f e)))
  (newline)