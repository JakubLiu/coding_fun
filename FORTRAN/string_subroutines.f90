! subroutine to return the length of a string
subroutine string_len(string, length)
        integer, intent(out) :: length
        character(len=1000), intent(in) :: string
        length = len(trim(string))
end subroutine string_len

! subroutine to concatenate two strings
subroutine concat_str(str1, str2, str3)
        character(len=1000), intent(out) :: str31
        character(len=1000), intent(in) :: str1, str2
        character(len=*) :: str
        str31 = trim(str1)//trim(str2)
        str3 = trim(str31)
end subroutine concat_str



program string_subroutines
        implicit none
        character(len=1000) :: str
        character(len = 1000) :: string1
        character(len = 1000) :: string2
        character(len = 1000) :: string3
        integer :: out_length
        
        str = 'Noovera'
        call string_len(str, out_length) ! testing the string_len() subroutine
        write(*,*) out_length

        string1 = "aaaa"
        string2 = "bbbbb"
        call concat_str(string1, string2, string3)    ! testing the str_concat() subroutine
        write(*,*) string3
end program string_subroutines
