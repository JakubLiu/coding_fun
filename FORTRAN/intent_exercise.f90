subroutine add(a,b, res)
        integer, intent(in) :: a, b   ! is only input
        integer, intent(out) :: res    ! is only output
        res = a + b
end subroutine add


subroutine add_v2(a,b)
        integer, intent(in) :: b       ! is only input
        integer, intent(in out) :: a    ! is input, gets updated and becomes output
        a = a + b
end subroutine add_v2



program intent_exercise
        implicit none
        integer :: add_out
        integer :: add_v2_input = 2   ! here we specify the intent inout argument

        call add(2,5,add_out)
        print*, add_out

        call add_v2(add_v2_input,5)   ! call a subroutine which has an intent inout argument

end program intent_exercise
