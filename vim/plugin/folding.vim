function! MyFoldText()
    let line = getline(v:foldstart)
    let foldedlinecount = v:foldend - v:foldstart + 1
    return "   " . foldedlinecount . " " . trim(substitute(line, "// {{{", "", ""))
endfunction

set foldtext=MyFoldText()
set fillchars=fold:\ 
" highlight Folded guibg=#2c323c

set foldmethod=marker
" set nofoldenable


