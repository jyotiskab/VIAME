###
# Application level pipelines
##

set( EXAMPLE_INSTALL_FILES
     README.rst
     input_list.txt )

if( WIN32 )
  set( EXAMPLE_INSTALL_FILES
       ${EXAMPLE_INSTALL_FILES}
       run_mouss_tracker.bat
       run_simple_tracker.bat
       run_tut_tracker.bat
       run_track_viewer.bat )
elseif( APPLE )
  set( EXAMPLE_INSTALL_FILES
       ${EXAMPLE_INSTALL_FILES}
       run_mouss_tracker.sh
       run_simple_tracker.sh
       run_tut_tracker.sh
       run_track_viewer.mac.sh )
else()
  set( EXAMPLE_INSTALL_FILES
       ${EXAMPLE_INSTALL_FILES}
       run_mouss_tracker.sh
       run_simple_tracker.sh
       run_tut_tracker.sh
       run_track_viewer.sh )
endif()

###
# Install pipelines to example directory
##
install( FILES       ${EXAMPLE_INSTALL_FILES}
         DESTINATION examples/object_tracking )
install( FILES       output/view_tracks.prj
         DESTINATION examples/object_tracking/output )
