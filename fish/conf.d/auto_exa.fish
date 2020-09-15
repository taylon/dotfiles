function __autoexa_hook --description "Auto exa" --on-event fish_prompt
  if test "$__autoexa_last" != (pwd)
    if test "$HOME" = (pwd)
    else
        exa --icons
    end
  end

  set  -g __autoexa_last (pwd)
end
