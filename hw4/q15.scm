(define duple
	 (lambda (n x)
	   (cond
	    ((zero? n) '())
	    (else
	     (cons x (duple (- n 1) x))))))

(display (duple 2 3))
(newline)
(display (duple 4 '(ha ha)))
(newline)
(display (duple 0 '(blah)))
(newline)




