(define memories '(
        (memory HighCode
                (address (#x040000 . #x04fFFF))
                (section
                        (programStart #x0010000)
                        farcode
                        data_init_table
                        ifar
                )
        )

        (memory HighData
                (address (#x050000 . #x06FFFF))
                (section
                        cfar
												idata
                )
        )

       (memory HighDataF
                (address (#x070000 . #x07FFFF))
                (section
												far
                        cdata
                )
        )

        (memory LowCode
                (address (#x00f000 . #x00FFFF))
                (section
                        code
                        switch
                )
        )

        (memory LowData
                (address (#x000400 . #x00bfff))
                (section
                        heap
                        data
                        zfar
                        zdata)
        )

        (memory stack
                (address (#x00C800 . #x00CFFF))
                (section (stack #x00C800))
        )
        (memory cstack
                (address (#x00C000 . #x00C7FF))
                (section (cstack #x00C000))
        )

        (memory DirectPage
                (address (#x000000 . #x0000FF))
                (section
                        (vectorTable #x000000)
                        (registers #x000004)
                )
        )

        (block cstack (size #x400))               ; C stack size

        (block stack  (size #x800))               ; machine stack size

        (base-address _DirectPageStart DirectPage 0)

        (base-address _NearBaseAddress LowData    0)
))
