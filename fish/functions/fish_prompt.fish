function my_prompt_pwd --description "Print the current working directory, shortened to fit the prompt"
    echo $PWD | sed -e "s|^$HOME|~|" | awk -F/ '{
      str = $NF
      currfield = NF - 1
      maxlen = 20       # Change this to increase/decrease the number of folders shown
      while (currfield > 0 \
             && length(str) + length($currfield) + 1 < maxlen \
             && length($currfield) > 0 ) {
        str = $currfield "/" str
        currfield = currfield-1
      }
      if ( currfield > 1 ) {
        str = "../" str;
      }
      if ( currfield > 0 ) {
        str= $1 "/" str
      }
      print str
    }'
end

function my_vim_mode --description "Display the current Vi mode"
    # Do nothing if not in vi mode
    if test "$fish_key_bindings" = "fish_vi_key_bindings"
        or test "$fish_key_bindings" = "fish_hybrid_key_bindings"
        switch $fish_bind_mode
            case default
                set_color red --bold
            case insert
                set_color white --bold
            case replace-one
                set_color white --bold
            case visual
                set_color magenta --bold
        end

        echo ' > '
        set_color normal
    else
      set_color white --bold
      echo ' > '
      set_color normal
    end
end

function fish_prompt
  set -g __fish_git_prompt_color_branch yellow --bold
  set -g __fish_git_prompt_color_prefix yellow --bold
  set -g __fish_git_prompt_color_suffix yellow --bold

  set -g __fish_git_prompt_color_untrackedfiles magenta --bold
  set -g __fish_git_prompt_color_dirtystate red --bold
  set -g __fish_git_prompt_color_stagedstate green --bold

  set -g __fish_git_prompt_char_stagedstate '+'
  set -g __fish_git_prompt_char_dirtystate '•'
  set -g __fish_git_prompt_char_untrackedfiles '#'
  set -g __fish_git_prompt_char_invalidstate '✖'
  set -g __fish_git_prompt_char_conflictedstate '✖'
  set -g __fish_git_prompt_char_cleanstate '✔'

  set -g __fish_git_prompt_showcolorhints 1
  set -g __fish_git_prompt_showdirtystate 1
  set -g __fish_git_prompt_showstashstate 1
  set -g __fish_git_prompt_showuntrackedfiles 1

  printf '\n'

  set_color $fish_color_cwd
  printf '%s' (my_prompt_pwd)
  set_color normal

  printf '%s' (__fish_git_prompt)

  printf '%s' (my_vim_mode)

  set_color normal
end
