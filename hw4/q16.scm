(define invert
    (lambda (lst)
      (cond
        ((null? lst)
         '())
        (else(cons(list(cadr(car lst))(car(car lst)))
                  (invert(cdr lst)))))))


(display (invert '((a 1)(a 2)(1 b)(2 b))))
(newline)