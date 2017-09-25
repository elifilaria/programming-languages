(define count-occurrences
    (lambda (s slist)
      (cond
        ((null? slist) 0)
        (else (let ([sexp (car slist)])
                (+ (if (pair? sexp)
                       (count-occurrences s sexp)
                       (if (eqv? sexp s) 1 0))
                   (count-occurrences s (cdr slist))))))))



(display (count-occurrences 'x '((f x) y (((x z) x)))))
(newline)
(display (count-occurrences 'x '((f x) y (((x z) () x)))))
(newline)
(display (count-occurrences 'w '((f x) y (((x z) x)))))
(newline)