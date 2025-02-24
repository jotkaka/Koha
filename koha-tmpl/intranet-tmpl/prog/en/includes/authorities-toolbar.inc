[% IF ( authid || CAN_user_editauthorities) %]

    <div id="toolbar" class="btn-toolbar">
        [% IF ( CAN_user_editauthorities ) %]
            <div class="btn-group">
                <button class="btn btn-default dropdown-toggle" data-toggle="dropdown">
                    <i class="fa fa-plus"></i> New authority
                    <span class="caret"></span>
                </button>
                <ul class="dropdown-menu">
                    [% FOREACH authority_type IN authority_types %]
                        <li><a href="/cgi-bin/koha/authorities/authorities.pl?authtypecode=[% authority_type.authtypecode | uri %]">[% authority_type.authtypetext | html %]</a></li>
                    [% END %]
                </ul>
            </div>
            [% IF servers.count > 0 %]
                <div class="btn-group">
                    <button id="z3950_new" class="btn btn-default">
                        <i class="fa fa-search"></i> New from Z39.50/SRU
                    </button>
                </div>
            [% END %]
        [% END %]

        [% IF ( authid ) %]
            [% IF ( CAN_user_editauthorities ) %]
                <div class="btn-group">
                    <button class="btn btn-default dropdown-toggle" data-toggle="dropdown">
                        <i class="fa-solid fa-pencil" aria-hidden="true"></i> Edit <span class="caret"></span>
                    </button>
                    <ul class="dropdown-menu">
                        <li><a id="editAuth" href="/cgi-bin/koha/authorities/authorities.pl?authid=[% authid | html %]">Edit record</a></li>
                        <li><a id="dupAuth" href="/cgi-bin/koha/authorities/authorities.pl?authid=[% authid | html %]&amp;op=duplicate">Edit as new (duplicate)</a></li>
                        [% IF servers.count > 0 %]
                        [% IF CAN_user_nukat_merge_auth %]
                            <li><a id="z3950_replace" href="#">Replace record via Z39.50/SRU</a></li>
                        [% END %]
                        [% END %]
                        [% UNLESS ( count ) or ! CAN_user_nukat_delete_auth %]
                            <li><a href="#" id="delAuth">Delete record</a></li>
                        [% END %]
                    </ul>
                </div>
            [% END %]

            <div class="btn-group">
                <a class="btn btn-default dropdown-toggle" data-toggle="dropdown" href="#"><i class="fa fa-download"></i> Save
                <span class="caret"></span>
                </a>
                <ul class="dropdown-menu">
                    <li><a href="/cgi-bin/koha/authorities/export.pl?format=mads&amp;op=export&amp;authid=[% authid | uri %]">MADS (XML)</a></li>
                    <li><a href="/cgi-bin/koha/authorities/export.pl?format=marcxml&amp;op=export&amp;authid=[% authid | uri %]">MARCXML</a></li>
                    <li><a href="/cgi-bin/koha/authorities/export.pl?format=marc8&amp;op=export&amp;authid=[% authid | uri %]">MARC (non-Unicode/MARC-8)</a></li>
                    <li><a href="/cgi-bin/koha/authorities/export.pl?format=utf8&amp;op=export&amp;authid=[% authid | uri %]">MARC (Unicode/UTF-8)</a></li>
                </ul>
            </div>
        [% END %]
    </div>

[% END %]
