program quadratic_eq_solver
        implicit none
        real :: a, b, c, delta, delta_sqrt, real_root, real_root1, real_root2
        complex, parameter :: i = (0, 1)
        complex :: delta_complex, complex_root1, complex_root2

        print*, 'Input the coefficients a,b,c in the equation ax**2 + bx + c = 0'
        
        print*, 'Input a: '
        read*, a
        a = real(a)            ! if the user has entered an integer, cast variable a to type real

        print*, 'Input b: '
        read*, b
        b = real(b)            ! if the user has entered an integer, cast variable b to type real

        print*, 'Input c: '
        read*, c
        c = real(c)            ! if the user has entered an integer, cast variable c to type real
        print*, '====================================================================================================='

        delta = (b*b)-4*(a*c)

        ! based on delta, decide what to do next

        ! two real roots
        positive_delta: if (delta > 0) then
                                delta_sqrt = sqrt(delta)
                                real_root1 = ((-1.00)*b + delta_sqrt) / (2.00*a)
                                real_root2 = ((-1.00)*b - delta_sqrt) / (2.00*a)
                                print*, 'first real root: ', real_root1
                                print*, 'second real root: ', real_root2
                        end if positive_delta
        
        ! one real root
        zero_delta: if (delta == 0) then
                                delta_sqrt = sqrt(delta)
                                real_root = ((-1.00)*b) / (2.00*a)
                                print*, 'real root: ', real_root
                    end if zero_delta

         ! two imaginary roots
         negative_delta: if (delta < 0) then
                                delta_sqrt = sqrt((-1.00)*delta)
                                delta_complex = complex(0.00, delta_sqrt)
                                complex_root1 = ((-1.00*b) + delta_complex) / (2.00*a)
                                complex_root2 = ((-1.00*b) - delta_complex) / (2.00*a)
                                print*, 'first complex root: ', complex_root1
                                print*, 'second complex root: ', complex_root2
                         end if negative_delta

end program quadratic_eq_solver
