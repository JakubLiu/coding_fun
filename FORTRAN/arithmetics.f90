module arithmetics

        use iso_fortran_env, only: int32, real32
        implicit none

        contains
                pure elemental function add(a,b) result(res)
                        real(real32), intent (in) :: a
                        real(real32), intent (in) :: b
                        real(real32) :: res
                        res = a + b
                end function add


                pure elemental function substract(a,b) result(res)
                        real(real32), intent (in) :: a
                        real(real32), intent (in) :: b
                        real(real32) :: res
                        res = a - b
                end function substract

                pure elemental function multiply(a,b) result(res)
                        real(real32), intent (in) :: a
                        real(real32), intent (in) :: b
                        real(real32) :: res
                        res = a * b
                end function multiply

end module arithmetics
