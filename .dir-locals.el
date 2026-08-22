;; ((c++-mode . ((eval . (setq compile-command
                            ;; (format "clang++ -std=c++20 -DONLINE_JUDGE -I.. %s ../catch_amalgamated.cpp -o solutions && ./solutions"
                                    ;; (file-name-nondirectory (or buffer-file-name ""))))))))

;; auto-compile on save
((c++-mode . ((eval . (add-hook 'after-save-hook
                                (lambda ()
                                  (compile "clang++ -std=c++20 -DONLINE_JUDGE -I.. remove_duplicates_from_sorted_array_26.cpp ../catch_amalgamated.cpp -o solutions && ./solutions"))
                                nil t)))))
