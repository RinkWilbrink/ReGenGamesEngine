INDX( 	 	xBr           (   8   �       ~ 0}                                =�    �`yx����`yx����yx����`yx����      �              T a r g e t D i r e c t o r i e s . t x t                  =�    �`yx����`yx����yx����`yx����      �              T A R G E T ~ 1 . T X T . T M               =�    �`yx����`yx����yx����`yx����      �              T A R G E T ~ 1 . T X T . T M               =�    �`yx����`yx����yx����`yx����      �              T A R G E T  1 . T X T . T M               p Z     =�    �`yx����`yx����yx����`yx����      �              T A R G E T ~ 1 . T X T . T M               �`yx����`yx����yx����`yx����      �              T A R G E T ~ 1 . T X T . T M                     source_loc{}, loggers_name, lvl, view)
    {
    }

    log_msg(const log_msg &other) = default;

    const std::string *logger_name{nullptr};
    level::level_enum level{level::off};
    log_clock::time_point time;
    size_t thread_id{ ;
    size_t msg_id{0};

    // wrapping the formatted text with color (updated by pattern_formatter).
    mutable size_t color_range_start{0};
    mutable size_t color_range_end{0};

    source_loc source;
    const string_view_t payload;
};
} // namespace details
} // namespace spdlog
